#ifndef RPC_HPP
#define RPC_HPP

#include <string>
#include "app/stats/command/command.pb.h"

std::string GenerateUUID();

int RPCHandlerService();

int RPCStatsService(v2ray::core::app::stats::command::QueryStatsResponse * = nullptr);

#endif