#include <iostream>
#include <gflags/gflags.h>
#include <thread>

#include "handler_service_client.hpp"
#include "stats_service_client.hpp"
#include "gflags.hpp"
#include "rpc.hpp"
#include "cluster.hpp"
#include "app/stats/command/command.pb.h"
#include "redis.pb.h"
#include "common.hpp"

using namespace std;

using redis::Stats;
using v2ray::core::app::stats::command::QueryStatsResponse;

// define flags
DEFINE_string(server, "localhost:10085", "v2ray Api address");
DEFINE_bool(write_config, false, "write to v2ray config");
DEFINE_string(operation, "", "The operation that you want to do. \
             It can be \"add_user\", \"remove_user\", \"get_sys_stats\", \"query_stats\",\"get_stats\".");
DEFINE_string(inbound_tag, "", "The tag of the inbound which you want to alter.");
DEFINE_string(v2ray_config, "/usr/local/etc/v2ray/config.json", "The config file of v2ray.");
DEFINE_string(protocol, "", "The protocol of inbound config. It can be vmess/vless");
DEFINE_string(name, "", "The inbound user that will be add/remove.");
DEFINE_string(id, "", "The id is needed when add user. If id is not entered, program will random generate one.");
DEFINE_string(query_pattern, "", "The pattern of query stats. If \"operation=query_stats\", it is needed. It can be empty.");
DEFINE_string(stats_name, "", "The pattern of get stats. If \"operation=get_stats\", it is needed. It can not be empty");
DEFINE_bool(reset, false, "Whether to reset stats account");
DEFINE_bool(cluster_mode, false, "Whether to use cluster mode");
DEFINE_string(redis_server, "localhost", "Redis address");
DEFINE_int32(redis_port, 6375, "Redis port");
DEFINE_string(redis_user, "", "The redis user name.(Redis > 6.0)");
DEFINE_string(redis_password, "", "It is useful when redis auth.");
DEFINE_string(redis_channel, "", "The cluster node subscribe channel. We suggest set it as ip.");
DEFINE_string(local_stats_file, "lvstats.db", "The local file which store all local stats.");
DEFINE_uint64(update_local_stats_time, 600, "How long time to auto update local stats file.");


int main(int argc, char **argv)
{
    gflags::SetVersionString("0.9");
    string usage_message = "add or remove v2ray inbound user. Query stats info.";
    gflags::SetUsageMessage(usage_message);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    // 每次运行都更新一次
    CountLocalStats(FLAGS_local_stats_file);

    if (FLAGS_cluster_mode)
    {
        // 以线程的方式自动更新本地统计信息
        thread auto_updaste_local_stats(AutoUpdasteLocalStats);
        return Cluster();
    }

    int code = 0;

    if (FLAGS_operation == "")
    {
        cout << "Operation parameter missing." << endl;
        code = -1;
    }
    else if (FLAGS_operation == ADD_USER_OPERATION || FLAGS_operation == REMOVE_USER_OPERATION)
    {
        code = RPCHandlerService();
    }
    else if (FLAGS_operation == QUERY_STATS_REQUEST_OPERATION ||
             FLAGS_operation == GET_STATS_REQUEST_OPERATION ||
             FLAGS_operation == SYS_STATS_REQUEST_OPERATION)
    {
        QueryStatsResponse query_stats_response_pointer;
        code = RPCStatsService(&query_stats_response_pointer);

        vector<Stats> stats;
        ParseV2rayStatToRedisStats(&query_stats_response_pointer, stats);

        for (const auto &stat : stats)
        {
            cout << "Type: " << stat.type() << endl;
            cout << "Name: " << stat.name() << endl;
            cout << "Downlink: " << stat.downlink() / 1024 / 1024 << "MB" << endl;
            cout << "Uplink: " << stat.uplink() / 1024 / 1024 << "MB" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Unsupport operation: " << FLAGS_operation << endl;
        code = -1;
    }

    return code;
}