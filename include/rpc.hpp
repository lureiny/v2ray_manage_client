#ifndef RPC_HPP
#define RPC_HPP

#include <string>
#include "app/stats/command/command.pb.h"
#include "operation.hpp"

std::string GenerateUUID();

int RPCHandlerService(operation_struct &operation_struct);

int RPCStatsService(operation_struct &operation_struct, v2ray::core::app::stats::command::QueryStatsResponse * = nullptr);

#endif