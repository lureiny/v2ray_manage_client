#pragma once

#include "src/app/stats/command/command.grpc.pb.h"

namespace v2m {
namespace client {
class StatsServiceClient {
 public:
  explicit StatsServiceClient(v2ray::core::app::stats::command::StatsService::StubInterface* stub) : stub_{stub} {}

  inline bool QueryStats(const v2ray::core::app::stats::command::QueryStatsRequest& query_stats_request,
                         v2ray::core::app::stats::command::QueryStatsResponse* query_stats_response) {
    grpc::ClientContext context;
    grpc::Status status = stub_->QueryStats(&context, query_stats_request, query_stats_response);
    return status.ok();
  }

  inline bool GetSysStats(const v2ray::core::app::stats::command::SysStatsRequest& sys_stats_request,
                          v2ray::core::app::stats::command::SysStatsResponse* sys_stats_response) {
    grpc::ClientContext context;
    grpc::Status status = stub_->GetSysStats(&context, sys_stats_request, sys_stats_response);
    return status.ok();
  }

 private:
  // 创建服务器链接
  std::unique_ptr<v2ray::core::app::stats::command::StatsService::StubInterface> stub_;
};
}  // namespace client
}  // namespace v2m
