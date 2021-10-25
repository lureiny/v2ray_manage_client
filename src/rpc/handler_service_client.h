#pragma once

#include <grpc/grpc.h>
#include <grpcpp/channel.h>

#include <string>

#include "src/app/proxyman/command/command.grpc.pb.h"
#include "src/app/proxyman/command/command.pb.h"
#include "src/user.h"

namespace v2m::client {
class HandlerServiceClient {
 public:
  explicit HandlerServiceClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(v2ray::core::app::proxyman::command::HandlerService::NewStub(channel)){};

  // Send the "AlterInboundRequest" to v2ray api interface.
  template <class Account>
  bool AddUser(const v2m::user::User<Account>& user);
  template <class Account>
  bool RemoveUser(const v2m::user::User<Account>& user);

 private:
  std::unique_ptr<v2ray::core::app::proxyman::command::HandlerService::Stub> stub_;

  // Base method to send alter inbound request. The "AddUser" and "RemoveUser" will all use this method.
  inline grpc::Status AlterInbound(
      const v2ray::core::app::proxyman::command::AlterInboundRequest& alter_inbound_request);
};
}  // namespace v2m::client
