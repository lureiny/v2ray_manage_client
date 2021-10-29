#pragma once

#include "src/app/proxyman/command/command.grpc.pb.h"
#include "src/rpc_client/handler_service_client.h"
#include "src/rpc_client/parameter_strcut.h"
#include "src/rpc_client/stats_service_client.h"

namespace v2m {
namespace client {
// Base client interface, the entrance of all rpc request.
class BaseClientInterface {
 public:
  // Init stub info.The method can reentry. When the object reinit by this method. The host_ will be changed.
  virtual bool Init(const InputParameter& input_parameter) = 0;

  // All rpc request will be send by this method.
  virtual bool RequestRemote(const InputParameter& input_parameter) = 0;

 private:
  std::string host_;
};

class BaseHandlerClient final : public BaseClientInterface {
 public:
  ~BaseHandlerClient() {
    delete handler_client_;
    // TODO: 这里可能会core dump, 需要测试
    delete stub_;
  }
  virtual bool RequestRemote(const InputParameter& input_parameter) override;
  virtual bool Init(const InputParameter& input_parameter) override;

 private:
  v2ray::core::app::proxyman::command::HandlerService::Stub* stub_;
  HandlerServiceClient* handler_client_;
}

class BaseStatsClient final : public BaseClientInterface {
 public:
  ~BaseStatsClient() {
    delete stats_client_;
    // TODO: 这里可能会core dump, 需要测试
    delete stub_;
  }
  virtual bool RequestRemote(const InputParameter& input_parameter) override;
  virtual bool Init(const InputParameter& input_parameter) override;

 private:
  v2ray::core::app::stats::command::StatsService::Stub* stub_;
  StatsServiceClient* stats_client_;
}
}  // namespace client
}  // namespace v2m
