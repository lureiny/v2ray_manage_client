#ifndef STATS_SERVICE_CLIENT
#define STATS_SERVICE_CLIENT

#include <string>
#include <algorithm>
#include <memory>
#include <grpcpp/channel.h>

#include "app/stats/command/command.grpc.pb.h"

const std::string QUERY_STATS_REQUEST_OPERATION = "query_stats";
const std::string GET_STATS_REQUEST_OPERATION = "get_stats";
const std::string SYS_STATS_REQUEST_OPERATION = "get_sys_stats";

class StatsServiceClient
{
public:
    StatsServiceClient(std::shared_ptr<grpc::Channel>);
    // 获取指定用户
    bool GetStats(const std::string &, bool = false);
    // 使用通配符查询多个
    bool QueryStats(const std::string & = "", bool = false, v2ray::core::app::stats::command::QueryStatsResponse * = nullptr);
    // 查询系统信息
    bool GetSysStats(v2ray::core::app::stats::command::SysStatsResponse * = nullptr);

private:
    // 创建服务器链接
    std::unique_ptr<v2ray::core::app::stats::command::StatsService::Stub> _stub;

    v2ray::core::app::stats::command::GetStatsRequest get_stats_request;
    v2ray::core::app::stats::command::QueryStatsRequest query_stats_requests;
    v2ray::core::app::stats::command::SysStatsRequest sys_stats_requests;
};
#endif