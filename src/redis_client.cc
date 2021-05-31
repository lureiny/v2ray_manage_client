#include <string>
#include <hiredis/hiredis.h>
#include <iostream>
#include <unordered_map>

#include "callback.hpp"
#include "redis_client.hpp"

using namespace std;

RedisClient::RedisClient(const string &host, const int port)
    : _host(host), _port(port)
{
    _InitContext();
}

void RedisClient::_InitContext()
{
    bool result = _MakeRedisContext(&_context);
    if ((result && _context->err) || !result)
    {
        exit(-1);
    }
}

bool RedisClient::_MakeRedisContext(redisContext **context)
{
    redisContext *r = redisConnect(_host.c_str(), _port);
    if (!r || r->err)
    {
        if (r)
        {
            cout << r->errstr << endl;
        }
        else
        {
            cout << "Can't allocate redis context" << endl;
            // TODO 抛出异常
            return false;
        }
    }
    *context = r;
    return true;
}

bool RedisClient::Auth(const std::string &password, const std::string &user)
{
    string cmd = "AUTH ";
    if (user == "")
    {
        cmd += password;
    }
    else
    {
        cmd += (user + " " + password);
    }
    return _ExcuteCommand(cmd.c_str());
}

void RedisClient::_OutputReply(redisReply *reply)
{
    if (reply)
    {
        for (size_t index = 0; index < reply->elements; ++index)
        {
            if (reply->element[index]->str)
            {
                cout << "[Remote]: " << reply->element[index]->str << endl;
            }
        }
    }
}

bool RedisClient::_ExcuteCommand(const char *cmd)
{
    if (!_context)
    {
        cout << "Redis context is unused" << endl;
    }
    _reply = (redisReply *)redisCommand(_context, cmd);
    if (!_reply)
    {
        if (_context->err)
        {
            // TODO 测试返回ERR时是否需要重新初始化context
            cout << _context->errstr << endl;
        }
        return false;
    }
    else if (_reply->type != REDIS_OK && _reply->str && string(_reply->str) != "OK")
    {
        cout << _reply->str << endl;
        return false;
    }
    _OutputReply(_reply);
    freeReplyObject(_reply);
    return true;
}

bool RedisClient::Subscribe(const std::string &channel, callback_func callback)
{
    string sub_cmd = "SUBSCRIBE " + channel;
    if (!_ExcuteCommand(sub_cmd.c_str()))
    {
        cout << "There is something wrng when subscribe " << channel << endl;
        return false;
    }
    while (true)
    {
        cout << "[*] Wati for redis subscribe channel" << endl;
        if (redisGetReply(_context, (void **)&_reply) == REDIS_OK)
        {
            if (_reply->elements != 3)
            {
                // TODO 抛出异常
                cout << "Subscribe message is wrong" << endl;
            }
            else if (_reply->element[2]->str)
            {
                cout << _reply->element[2]->str << endl;
                callback(_reply->element[2]->str, this);
            }
        }
        else
        {
            cout << "redis error: " << endl;
            exit(-1);
        }
        freeReplyObject(_reply);
    }
    return true;
}

bool RedisClient::ExcuteCommand(const char *cmd)
{
    return _ExcuteCommand(cmd);
}