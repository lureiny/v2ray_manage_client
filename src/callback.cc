#include <string>
#include <iostream>

#include "callback.hpp"
#include "redis.pb.h"
#include "gflags.hpp"
#include "rpc.hpp"
#include "handler_service_client.hpp"
#include "stats_service_client.hpp"
#include "app/stats/command/command.pb.h"
#include "common.hpp"
#include "rapidjson/rapidjson.h"
#include "file_io.hpp"
#include "local_stats.pb.h"
#include "redis_client.hpp"
#include "operation.hpp"

using namespace std;

using namespace rapidjson;

using local::LocalStats;
using redis::AddUserOperation;
using redis::AddUserOperationResponse;
using redis::GetStatsOperation;
using redis::GetStatsOperationResponse;
using redis::Operation;
using redis::RemoveUserOperation;
using redis::RemoveUserOperationResponse;
using redis::Response;
using redis::Stats;
using v2ray::core::app::stats::command::QueryStatsResponse;

void CallBack::_Callback(const char *data, RedisClient *redis_client)
{
    Operation operation;
    Response response;
    if (!operation.ParseFromArray(data, strlen(data)))
    {
        cout << "[Remote]: operation parse failed" << endl;
        return;
    }
    // 增加用户
    if (operation.type() == REDIS_ADD_USER_OPERATION)
    {
        _CallbackAddUser(&operation, &response);
    }
    // 删除用户
    else if (operation.type() == REDIS_REMOVE_USER_OPERATION)
    {
        _CallbackRemoveUser(&operation, &response);
    }
    // 流量查询操作
    else if (operation.type() == REDIS_GET_STATS_OPERATION)
    {
        _CallbackGetStats(&operation, &response);
    }
    // 其他操作
    else
    {
        cout << "[Remove]: unsupport operation " << operation.type() << endl;
    }

    // 上传构建好的response到redis
    _ResponseToRedis(&response, operation.channel(), redis_client);
}

void CallBack::_CallbackAddUser(const Operation *operation, Response *response)
{
    AddUserOperation add_user_operation;
    // 解析
    if (!add_user_operation.ParseFromString(operation->value()))
    {
        cout << "[Remote]: Add user operation parse failed" << endl;
        return;
    }
    operation_struct operation_struct;
    // 设置参数
    operation_struct.type = ADD_USER_OPERATION;
    operation_struct.inbound_tag = add_user_operation.tag();
    operation_struct.email = add_user_operation.email();
    operation_struct.protocol = add_user_operation.protocol();
    operation_struct.id = add_user_operation.id();
    // 添加操作
    int statu = RPCHandlerService(operation_struct);

    // 构建Response
    response->set_type(REDIS_ADD_USER_OPERATION_RESPONSE);
    AddUserOperationResponse add_user_operation_response;
    add_user_operation_response.set_statu(true ? statu == 0 : false);
    add_user_operation_response.set_ip(FLAGS_redis_channel);
    add_user_operation_response.set_allocated_add_user_operation(&add_user_operation);

    response->set_value(add_user_operation_response.SerializeAsString());

    // 释放add_user_operation_response中的add_user_operation，防止出现重复释放内存的问题
    add_user_operation_response.release_add_user_operation();

    // 更新配置文件
    if (FLAGS_write_config)
    {
        _UpdateConfig(FLAGS_v2ray_config, add_user_operation);
    }
}

void CallBack::_CallbackRemoveUser(const redis::Operation *operation, redis::Response *response)
{
    RemoveUserOperation remove_user_operation;
    // 解析
    if (!remove_user_operation.ParseFromString(operation->value()))
    {
        {
            cout << "[Remote]: Remove user operation parse failed" << endl;
            return;
        }
    }
    operation_struct operation_struct;
    // 设置参数
    operation_struct.type = REMOVE_USER_OPERATION;
    operation_struct.inbound_tag = remove_user_operation.tag();
    operation_struct.email = remove_user_operation.email();
    // 添加操作
    int statu = RPCHandlerService(operation_struct);

    // 构建Response
    response->set_type(REDIS_REMOVE_USER_OPERATION_RESPONSE);
    RemoveUserOperationResponse remove_user_operation_response;
    remove_user_operation_response.set_statu(true ? statu == 0 : false);
    remove_user_operation_response.set_ip(FLAGS_redis_channel);
    remove_user_operation_response.set_allocated_remove_user_operation(&remove_user_operation);

    response->set_value(remove_user_operation.SerializeAsString());

    // 释放remove_user_operation_response中的remove_user_operation，防止出现重复释放内存的问题
    remove_user_operation_response.release_remove_user_operation();

    if (FLAGS_write_config)
    {
        _UpdateConfig(FLAGS_v2ray_config, remove_user_operation);
    }
}

void CallBack::_CallbackGetStats(const redis::Operation *operation, redis::Response *response)
{

    // 对于任何流量查询，都更新本地文件信息
    // 每次流量查询都更新local_static_file
    if (!CountLocalStats(FLAGS_local_stats_file, FLAGS_server))
    {
        return;
    }

    GetStatsOperation get_stats_operation;
    if (!get_stats_operation.ParseFromString(operation->value()))
    {
        cout << "[Remote]: Get stats operation parse failed" << endl;
        return;
    }

    operation_struct operation_struct;

    GetStatsOperationResponse get_stats_operation_response;
    operation_struct.type = QUERY_STATS_REQUEST_OPERATION;
    // 查询全部流量
    if (get_stats_operation.type() == REDIS_GET_ALL_STATS)
    {
        _CallbackGetAllStats(&get_stats_operation_response);
    }
    // 根据用户名查询
    else if (get_stats_operation.type() == REDIS_GET_USER_STATS ||
             get_stats_operation.type() == REDIS_GET_INBOUND_STATS)
    {
        operation_struct.query = get_stats_operation.name();
        const string user_or_inbound = get_stats_operation.type() == REDIS_GET_USER_STATS ? "user" : "inbound";
        _CallbackGetUserOrInoundStats(operation_struct, &get_stats_operation_response, user_or_inbound);
    }
    // 其他查询
    else
    {
        cout << "[Remote]: Unsupport stats operation " << get_stats_operation.type() << endl;
        return;
    }
}

void CallBack::_CallbackGetAllStats(GetStatsOperationResponse *get_stats_operation_response)
{
    LocalStats local_stats;
    if (!ReadLocalStats(FLAGS_local_stats_file, local_stats))
    {
        return;
    }

    // online
    for (size_t index = 0; index < local_stats.online().stats_size(); ++index)
    {
        get_stats_operation_response->add_stats()->CopyFrom(local_stats.online().stats(index));
    }

    // history
    for (size_t index = 0; index < local_stats.history().stats_size(); ++index)
    {
        get_stats_operation_response->add_stats()->CopyFrom(local_stats.history().stats(index));
    }
}

void CallBack::_CallbackGetUserOrInoundStats(operation_struct &operation_struct, GetStatsOperationResponse *get_stats_operation_response, const string &user_or_inbound)
{
    // 查询
    QueryStatsResponse query_stats_response;
    RPCStatsService(operation_struct, &query_stats_response);

    // 解析
    vector<Stats> stats;
    ParseV2rayStatToRedisStats(&query_stats_response, stats);

    for (const auto &stat : stats)
    {
        get_stats_operation_response->add_stats()->CopyFrom(stat);
    }

    // 进一步解析，根据检索类型过滤结果
    GetStatsOperationResponse t;
    for (size_t index = 0; index < get_stats_operation_response->stats_size(); ++index)
    {
        if (get_stats_operation_response->stats(index).type() == user_or_inbound)
        {
            t.add_stats()->CopyFrom(get_stats_operation_response->stats(index));
        }
    }
    get_stats_operation_response->clear_stats();
    get_stats_operation_response->CopyFrom(t);
}

bool CallBack::_ResponseToRedis(Response *response, const string &channel, RedisClient *redis_client)
{
    string cmd = "PUBLISH " + channel + response->SerializeAsString();
    if (redis_client)
    {
        return redis_client->ExcuteCommand(cmd.c_str());
    }
    else
    {
        return false;
    }
}

bool CallBack::_UpdateConfig(const string &config, const AddUserOperation &add_user_operation)
{
    Document root;
    if (!ReadJson(config.c_str(), &root))
    {
        return false;
    }

    if (!AddUserToConfig(&root, add_user_operation.tag(), add_user_operation.email(), add_user_operation.id()))
    {
        return false;
    }

    return WriteJson(config.c_str(), &root);
}

bool CallBack::_UpdateConfig(const string &config, const RemoveUserOperation &remove_user_operation)
{
    Document root;
    if (!ReadJson(config.c_str(), &root))
    {
        return false;
    }

    if (!RemoveUserFromConfig(&root, remove_user_operation.tag(), remove_user_operation.email()))
    {
        return false;
    }

    return WriteJson(config.c_str(), &root);
}

void CallBack::Run(const char *data, RedisClient *redis_client)
{
    return _Callback(data, redis_client);
}