#pragma once

#include <string>

#include "src/app/stats/command/command.grpc.pb.h"

namespace v2m {
struct InputParameter {
  std::string operation;     // The operation that you want to do. It can be "add_user", "remove_user", "get_sys_stats",
                             // "query_stats".
  std::string uuid;          // The id is needed when add user. If id is not entered, program will random generate one.
  std::string inbound_tag;   // The tag of the inbound which you want to alter.
  std::string name;          // The inbound user that will be add/remove
  std::string protocol;      // The protocol of inbound config. It can be vmess/vless
  std::string v2ray_config;  // The config file of v2ray.
  std::string host;          // GRPC host like localhost:1080
  bool write_config;         // write to v2ray config
};

// All will be nullptr when add/remove user.
union OutputParameter {
  void* common;
  v2ray::core::app::stats::command::SysStatsResponse* sys_stats_response;
  v2ray::core::app::stats::command::QueryStatsResponse* query_stats_response;
};
}  // namespace v2m
