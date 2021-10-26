#pragma once

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include <cstdio>
#include <iostream>

#include "src/app/proxyman/command/command.grpc.pb.h"
#include "src/app/proxyman/command/command.pb.h"
#include "src/app/proxyman/operation/alter_inbound_operation.h"
#include "src/common/protocol/user.pb.h"
#include "src/user.h"

namespace v2m::client {
class HandlerServiceClient {
 public:
  explicit HandlerServiceClient(v2ray::core::app::proxyman::command::HandlerService::StubInterface* stub)
      : stub_{stub} {};

  // Send the "AlterInboundRequest" to v2ray api interface.
  template <class Account>
  bool AddUser(const v2m::user::User<Account>& user);
  template <class Account>
  bool RemoveUser(const v2m::user::User<Account>& user);

 private:
  static constexpr char* kAddUserLog = (char*)"Add User[%s] to %s with %s.";
  static constexpr char* kRemoveUserLog = (char*)"Remove User[%s] from %s.";

  std::unique_ptr<v2ray::core::app::proxyman::command::HandlerService::StubInterface> stub_;

  // Base method to send alter inbound request. The "AddUser" and "RemoveUser" will all use this method.
  inline grpc::Status AlterInbound(
      const v2ray::core::app::proxyman::command::AlterInboundRequest& alter_inbound_request);
};

template <class Account>
bool HandlerServiceClient::AddUser(const v2m::user::User<Account>& user) {
  // Make the user which be send as grpc request's data.
  v2ray::core::common::protocol::User* grpc_user = new v2ray::core::common::protocol::User;
  user.InsertUserInfoToUserProtobuf(grpc_user);

  // Prepare operation info of AddUserOperation.
  v2m::operation::AlterInboundOperation<v2ray::core::app::proxyman::command::AddUserOperation> alter_inbound_operation;
  alter_inbound_operation.InsertDataToOpeartion(grpc_user);
  v2ray::core::common::serial::TypedMessage* typed_operation = new v2ray::core::common::serial::TypedMessage;
  alter_inbound_operation.InsertDataToTypedInboundOperation(typed_operation);

  // Make AlterInboundOperation of AddUserOperation.
  v2ray::core::app::proxyman::command::AlterInboundRequest alter_inbound_request;
  alter_inbound_request.set_tag(user.GetInboundTag());
  alter_inbound_request.set_allocated_operation(typed_operation);

  // Send request.
  grpc::Status status = AlterInbound(alter_inbound_request);

  if (!status.ok()) {
    std::cout << status.error_message() << std::endl;
    return false;
  }

  std::printf(kAddUserLog, user.GetEmail().c_str(), user.GetInboundTag().c_str(), user.GetUuid().c_str());
  return true;
}

template <class Account>
bool HandlerServiceClient::RemoveUser(const v2m::user::User<Account>& user) {
  // Prepare operation info of RemoveUserOperation.
  v2m::operation::AlterInboundOperation<v2ray::core::app::proxyman::command::RemoveUserOperation>
      alter_inbound_operation;
  alter_inbound_operation.InsertDataToOpeartion(user.GetEmail());
  v2ray::core::common::serial::TypedMessage* typed_operation = new v2ray::core::common::serial::TypedMessage;
  alter_inbound_operation.InsertDataToTypedInboundOperation(typed_operation);

  // Make AlterInboundOperation of RemoveUserOperation.
  v2ray::core::app::proxyman::command::AlterInboundRequest alter_inbound_request;
  alter_inbound_request.set_tag(user.GetInboundTag());
  alter_inbound_request.set_allocated_operation(typed_operation);

  // Send request.
  grpc::Status status = AlterInbound(alter_inbound_request);

  if (!status.ok()) {
    std::cout << status.error_message() << std::endl;
    return false;
  }

  std::printf(kRemoveUserLog, user.GetEmail().c_str(), user.GetInboundTag().c_str());
  return true;
}

inline grpc::Status HandlerServiceClient::AlterInbound(
    const v2ray::core::app::proxyman::command::AlterInboundRequest& alter_inbound_request) {
  grpc::ClientContext context;
  v2ray::core::app::proxyman::command::AlterInboundResponse alter_inbound_response;

  return stub_->AlterInbound(&context, alter_inbound_request, &alter_inbound_response);
}
}  // namespace v2m::client