#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include "redis.pb.h"
#include "redis_client.hpp"
#include "operation.hpp"
#include <string>

const std::string REDIS_ADD_USER_OPERATION = "redis.AddUserOperation";
const std::string REDIS_REMOVE_USER_OPERATION = "redis.RemoveUserOperation";
const std::string REDIS_GET_STATS_OPERATION = "redis.GetStatsOperation";
const std::string REDIS_GET_ALL_STATS = "redis.GetStatsOperation.all_stats";
const std::string REDIS_GET_USER_STATS = "redis.GetStatsOperation.user_stats";
const std::string REDIS_GET_INBOUND_STATS = "redis.GetStatsOperation.inbound_stats";

const std::string REDIS_ADD_USER_OPERATION_RESPONSE = "redis.AddUserOperationResponse";
const std::string REDIS_REMOVE_USER_OPERATION_RESPONSE = "redis.RemoveUserOperationResponse";
const std::string REDIS_GET_ALL_STATS_RESPONSE = "redis.GetStatsOperationResponse.all_stats";
const std::string REDIS_GET_USRR_STATS_RESPONSE = "redis.GetStatsOperationResponse.user_stats";
const std::string REDIS_GET_INBOUND_STATS_RESPONSE = "redis.GetStatsOperationResponse.inbound_stats";

class CallBack
{
public:
    static void Run(const char *, RedisClient *);

private:
    // 回调函数
    static void _Callback(const char *, RedisClient *);

    // 回调增加用户
    static void _CallbackAddUser(const redis::Operation *, redis::Response *);

    // 回调删除用户
    static void _CallbackRemoveUser(const redis::Operation *, redis::Response *);

    // 获取流量信息
    static void _CallbackGetStats(const redis::Operation *, redis::Response *);

    // 获取全部流量信息
    static void _CallbackGetAllStats(redis::GetStatsOperationResponse *);

    // 解析并过滤User/inbound流量
    static void _CallbackGetUserOrInoundStats(operation_struct &operation_struct, redis::GetStatsOperationResponse *, const std::string &);

    // 发送response到redis
    static bool _ResponseToRedis(redis::Response *, const std::string &channel, RedisClient *);

    // 更新配置文件
    static bool _UpdateConfig(const std::string &config, const redis::AddUserOperation &add_user_operation);
    static bool _UpdateConfig(const std::string &config, const redis::RemoveUserOperation &remove_user_operation);
};

#endif