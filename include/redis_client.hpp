#ifndef REDIS_CLIENT_HPP
#define REDIS_CLIENT_HPP

#include <hiredis/hiredis.h>
#include <string>

#include "redis.pb.h"
#include "app/stats/command/command.pb.h"


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

class RedisClient
{
public:
    RedisClient(const std::string & = "127.0.0.1", const int = 6379);

    // 验证用户权限
    bool Auth(const std::string &, const std::string & = "");

    // 订阅channel
    bool Subscribe(const std::string &);

    bool ExcuteCommand(const char *);

private:
    const std::string _host;
    const int _port;
    redisContext *_context;
    redisReply *_reply;

    // 初始化持久化链接
    void _InitContext();

    // 生成redis持久链接
    bool _MakeRedisContext(redisContext **);

    // 输出返回信息
    void _OutputReply(redisReply *);

    // 执行指定命令
    bool _ExcuteCommand(const char *);

    // 回调函数
    void _Callback(const char *);

    // 回调增加用户
    void _CallbackAddUser(const redis::Operation *, redis::Response *);

    // 回调删除用户
    void _CallbackRemoveUser(const redis::Operation *, redis::Response *);

    // 获取流量信息
    void _CallbackGetStats(const redis::Operation *, redis::Response *);

    // 获取全部流量信息
    void _CallbackGetAllStats(redis::GetStatsOperationResponse *);


    // 解析并过滤User/inbound流量
    void _CallbackGetUserOrInoundStats(redis::GetStatsOperationResponse *, const std::string &);

    // 发送response到redis
    bool _ResponseToRedis(redis::Response *, const std::string &channel);

    // 更新配置文件
    bool _UpdateConfig(const std::string &config, const redis::AddUserOperation &add_user_operation);
    bool _UpdateConfig(const std::string &config, const redis::RemoveUserOperation &remove_user_operation);
};

#endif