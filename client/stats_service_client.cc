#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "app/proxyman/command/command.grpc.pb.h"
#include "proxy/vmess/account.pb.h"
#include "proxy/vless/account.pb.h"

#include "stats_service_client.hpp"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using v2ray::core::app::stats::command::GetStatsRequest;
using v2ray::core::app::stats::command::GetStatsResponse;
using v2ray::core::app::stats::command::QueryStatsResponse;
using v2ray::core::app::stats::command::StatsService;
using v2ray::core::app::stats::command::SysStatsResponse;

StatsServiceClient::StatsServiceClient(std::shared_ptr<Channel> channel)
    : _stub(StatsService::NewStub(channel))
{
}

bool StatsServiceClient::GetStats(const string &name, bool reset)
{
    get_stats_request.set_name(name);
    get_stats_request.set_reset(reset);

    ClientContext context;
    GetStatsResponse get_stats_response;

    Status status = _stub->GetStats(&context, get_stats_request, &get_stats_response);
    if (status.ok())
    {
        cout << get_stats_response.stat().name() << ": ";
        cout << get_stats_response.stat().value() / 1024 / 1024 << "MB" << endl;
        return true;
    }
    else
    {
        cout << status.error_message() << endl;
        // TODO 抛出异常
        return false;
    }
}

bool StatsServiceClient::QueryStats(const string &pattern, bool reset)
{
    query_stats_requests.set_pattern(pattern);
    query_stats_requests.set_reset(reset);

    ClientContext context;
    QueryStatsResponse query_stats_response;

    Status status = _stub->QueryStats(&context, query_stats_requests, &query_stats_response);
    if (status.ok())
    {
        for (int i = 0; i < query_stats_response.stat_size(); ++i)
        {
            cout << query_stats_response.stat(i).name() << endl;
            cout << query_stats_response.stat(i).value() / 1024 / 1024 << "MB" << endl;
        }
        return true;
    }
    else
    {
        cout << status.error_message() << endl;
        // TODO 抛出异常
        return false;
    }
}

bool StatsServiceClient::GetSysStats() {
    ClientContext context;
    SysStatsResponse sys_stats_response;

    Status status = _stub->GetSysStats(&context, sys_stats_requests, &sys_stats_response);
    if (status.ok())
    {   
        cout << "NumGoroutine: " << sys_stats_response.numgoroutine() << endl;
        cout << "NumGC: " << sys_stats_response.numgc() << endl;
        cout << "Alloc: " << sys_stats_response.alloc() << endl;
        cout << "TotalAlloc: " << sys_stats_response.totalalloc() << endl;
        cout << "Sys: " << sys_stats_response.sys() << endl;
        cout << "Mallocs: " << sys_stats_response.mallocs() << endl;
        cout << "Frees: " << sys_stats_response.frees() << endl;
        cout << "LiveObjects: " << sys_stats_response.liveobjects() << endl;
        cout << "PauseTotalNs: " << sys_stats_response.pausetotalns() << endl;
        cout << "Uptime: " << sys_stats_response.uptime() << endl; 
        return true;
    }
    else
    {
        cout << status.error_message() << endl;
        // TODO 抛出异常
        return false;
    }
}