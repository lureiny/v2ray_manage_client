#include "cluster.hpp"
#include "gflags.hpp"
#include "redis_client.hpp"
#include "callback.hpp"

#include <iostream>
#include "common.hpp"
#include <thread>

using namespace std;

int Cluster()
{

    if (FLAGS_redis_server == "" || FLAGS_redis_port > 65535 || FLAGS_redis_port <= 0)
    {
        cout << "Wrong redis address " << FLAGS_redis_server << ":" << FLAGS_redis_port << endl;
        return -1;
    }
    RedisClient redis_client(FLAGS_redis_server, FLAGS_redis_port);
    if (!redis_client.Auth(FLAGS_redis_password, FLAGS_redis_user))
    {
        return -1;
    }
    if (FLAGS_redis_channel == "")
    {
        cout << "You must set channel. It should be ip" << endl;
        return -1;
    }
    return redis_client.Subscribe(FLAGS_redis_channel, CallBack::Run);
}

void AutoUpdasteLocalStats()
{
    while (true)
    {
        if (CountLocalStats(FLAGS_local_stats_file, FLAGS_server))
        {
            cout << "Local stats file  update." << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(FLAGS_update_local_stats_time * 1000));
    }
}