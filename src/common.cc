#include "common.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <ctime>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/filewritestream.h"

#include "redis.pb.h"
#include "handler_service_client.hpp"
#include "stats_service_client.hpp"
#include "app/stats/command/command.pb.h"
#include "local_stats.pb.h"
#include "gflags.hpp"

using namespace rapidjson;
using namespace std;

using local::LocalStats;
using redis::AddUserOperation;
using redis::Stats;
using v2ray::core::app::stats::command::QueryStatsResponse;
using v2ray::core::app::stats::command::SysStatsResponse;

bool FindInbound(Document *root, Value **node, const string &inbound_tag)
{
    if (!root->HasMember("inbounds"))
    {
        cout << "No inbounds in config." << endl;
        return false;
    }
    Value &inbounds = (*root)["inbounds"];
    if (!inbounds.IsArray())
    {
        cout << "No one inbound config." << endl;
        return false;
    }

    for (int i = 0; i < inbounds.Size(); ++i)
    {
        if (inbounds[i].HasMember("tag") && inbounds[i]["tag"].GetString() == inbound_tag)
        {
            *node = &inbounds[i];
            return true;
        }
    }
    cout << "Can not find the " << inbound_tag << " inbound." << endl;
    return false;
}

bool AddUserToConfig(Document *root, const string &tag, const string &email, const string &id)
{
    Value *inbound = nullptr;
    if (!FindInbound(root, &inbound, tag))
    {
        return false;
    }

    Value client(kObjectType);
    client.AddMember(Value("email", root->GetAllocator()).Move(), Value(email.c_str(), root->GetAllocator()).Move(), root->GetAllocator());
    string id_type = (*inbound)["protocol"].GetString() == PROTOCOL_VLESS || (*inbound)["protocol"].GetString() == PROTOCOL_VMESS ? "id" : "password";

    client.AddMember(Value(id_type.c_str(), root->GetAllocator()).Move(), Value(id.c_str(), root->GetAllocator()).Move(), root->GetAllocator());

    // 插入新的值
    (*inbound)["settings"]["clients"].PushBack(client.Move(), root->GetAllocator());
    return true;
}

bool RemoveUserFromConfig(rapidjson::Document *root, const std::string &tag, const std::string &email)
{
    Value *inbound = nullptr;
    if (!FindInbound(root, &inbound, tag))
    {
        return false;
    }

    for (Value::ConstValueIterator itr = (*inbound)["settings"]["clients"].Begin(); itr != (*inbound)["settings"]["clients"].End(); ++itr)
    {
        if ((*itr)["email"].GetString() == email)
        {
            (*inbound)["settings"]["clients"].Erase(itr);
            return true;
        }
    }
    return true;
}

void ParseV2rayStatToRedisStats(QueryStatsResponse *query_stats_response, vector<Stats> &stats)
{
    unordered_map<string, Stats> temp;
    for (size_t index = 0; index < query_stats_response->stat_size(); ++index)
    {
        string stat_name = query_stats_response->stat(index).name();
        long long stat_value = query_stats_response->stat(index).value();
        smatch sm;
        regex_search(stat_name, sm, REGEX);
        if (sm.size() != 4)
        {
            cout << "[Remote]: " << stat_name << "parse failed" << endl;
        }
        else
        {
            string key = string(sm[2]) + string(sm[1]);
            // 设置name
            if (temp.find(key) == temp.end())
            {
                temp[key] = Stats();
                temp[key].set_online(true);
                temp[key].set_name(string(sm[2]));
            }

            // 设置type
            if (sm[1] == "user")
            {
                temp[key].set_type("user");
            }
            else if (sm[1] == "inbound")
            {
                temp[key].set_type("inbound");
            }
            else
            {
                cout << "[Remote]: unkown stats type " << sm[1] << endl;
                temp.erase(key);
            }
            // 设置downlink/uplink
            if (sm[3] == "downlink")
            {
                temp[key].set_downlink(stat_value);
            }
            else if (sm[3] == "uplink")
            {
                temp[key].set_uplink(stat_value);
            }
            else
            {
                cout << "[Remote]: unkown stats link " << sm[3] << endl;
                temp.erase(key);
            }
        }
    }
    for (const auto &s : temp)
    {
        stats.push_back(s.second);
    }
}

bool ReadLocalStats(const string &local_file, LocalStats &local_stats)
{
    fstream input(local_file, ios::in | ios::binary);
    if (!input)
    {
        cout << "Local stats file open to read failed: " << local_file << endl;
        return false;
    }
    if (!local_stats.ParseFromIstream(&input))
    {
        cout << "Read local stats file parse failed." << endl;
        return false;
    }
    return true;
}

void MergeLocalStats(LocalStats *new_local_stats, LocalStats *old_local_stats)
{
    // 对于第一次统计的处理
    if (old_local_stats->online().stats_size() == 0 && old_local_stats->history().stats_size() == 0)
    {
        return;
    }

    // Copy History
    new_local_stats->mutable_history()->CopyFrom(old_local_stats->history());

    // 遍历old_local_stats
    unordered_map<string, Stats> old_online_stats_pair;
    unordered_set<string> old_online_stats_keys;
    for (size_t index = 0; index < old_local_stats->online().stats_size(); ++index)
    {
        string key = string(old_local_stats->online().stats(index).name()) + string(old_local_stats->online().stats(index).type());
        old_online_stats_keys.insert(key);
        old_online_stats_pair[key] = old_local_stats->online().stats(index);
    }

    // 遍历new_local_stats
    unordered_map<string, pair<int, Stats>> new_online_stats_pair;
    set<string> new_online_stats_keys;

    for (size_t index = 0; index < new_local_stats->online().stats_size(); ++index)
    {

        string key = string(new_local_stats->online().stats(index).name()) + string(new_local_stats->online().stats(index).type());
        new_online_stats_keys.insert(key);
        new_online_stats_pair[key] = make_pair(index, new_local_stats->online().stats(index));
    }

    // same_start_time = true 同一进程流量
    bool same_start_time = new_local_stats->last_start_time() - old_local_stats->last_start_time() <= 2;
    unordered_set<string> difference;
    set<string> same;

    set_difference(old_online_stats_keys.begin(), old_online_stats_keys.end(), new_online_stats_keys.begin(), new_online_stats_keys.end(), inserter(difference, difference.begin()));
    set_intersection(old_online_stats_keys.begin(), old_online_stats_keys.end(), new_online_stats_keys.begin(), new_online_stats_keys.end(), inserter(same, same.begin()));

    // 更新流量统计信息
    if (!same_start_time)
    {
        for (const auto &key : same)
        {
            long long downlink = new_local_stats->online().stats(new_online_stats_pair[key].first).downlink();
            long long uplink = new_local_stats->online().stats(new_online_stats_pair[key].first).uplink();
            downlink += old_online_stats_pair[key].downlink();
            uplink += old_online_stats_pair[key].uplink();
            new_local_stats->mutable_online()->mutable_stats(new_online_stats_pair[key].first)->set_downlink(downlink);
            new_local_stats->mutable_online()->mutable_stats(new_online_stats_pair[key].first)->set_uplink(uplink);
        }
    }

    // 更新历史信息
    for (const auto &key : difference)
    {
        if (new_online_stats_keys.find(key) == new_online_stats_keys.end())
        {
            old_online_stats_pair[key].set_online(false);
            // 不在new中在old中
            new_local_stats->mutable_history()->add_stats()->CopyFrom(old_online_stats_pair[key]);
        }
    }
}

bool WriteLocalStats(const string &local_file, LocalStats &local_stats)
{
    fstream output(local_file, ios::out | ios::binary | ios::trunc);
    if (!output)
    {
        cout << "Local stats file open to write failed: " << local_file << endl;
    }
    if (!local_stats.SerializeToOstream(&output))
    {
        cout << "Write to local stats file failed." << endl;
        return false;
    }
    output.close();
    return true;
}

bool CountLocalStats(const string &local_file)
{
    // 读取本地文件中上次统计情况
    LocalStats old_local_stats;
    ReadLocalStats(local_file, old_local_stats);

    // 获取当前统计情况
    QueryStatsResponse query_stats_response_pointer;
    StatsServiceClient stats_client(grpc::CreateChannel(FLAGS_server, grpc::InsecureChannelCredentials()));
    if (!stats_client.QueryStats("", false, &query_stats_response_pointer))
    {
        return false;
    }

    vector<Stats> stats;
    ParseV2rayStatToRedisStats(&query_stats_response_pointer, stats);

    // 更新到new_local_stats
    LocalStats new_local_stats;
    // 更新时间
    time_t time_stamp = time(nullptr);
    if (time_stamp == -1)
    {
        cout << "System time can not used." << endl;
        new_local_stats.set_last_start_time(0);
    }
    SysStatsResponse sys_stats_reponse;
    if (!stats_client.GetSysStats(&sys_stats_reponse))
    {
        return false;
    }
    new_local_stats.set_last_start_time(time_stamp - sys_stats_reponse.uptime());

    for (auto &stat : stats)
    {
        new_local_stats.mutable_online()->add_stats()->CopyFrom(stat);
    }

    MergeLocalStats(&new_local_stats, &old_local_stats);
    return WriteLocalStats(local_file, new_local_stats);
}