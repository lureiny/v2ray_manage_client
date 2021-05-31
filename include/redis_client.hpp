#ifndef REDIS_CLIENT_HPP
#define REDIS_CLIENT_HPP

#include <hiredis/hiredis.h>
#include <string>
#include "redis.pb.h"

class RedisClient
{
public:
    typedef void (*callback_func)(const char *, RedisClient *);
    RedisClient(const std::string & = "127.0.0.1", const int = 6379);

    // 验证用户权限
    bool Auth(const std::string &, const std::string & = "");

    // 订阅channel
    bool Subscribe(const std::string &, callback_func);

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
};

#endif
