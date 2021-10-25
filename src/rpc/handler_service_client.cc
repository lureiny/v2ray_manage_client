#include "src/rpc/handler_service_client.h"

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

namespace v2m::client {

constexpr char* kAddUserLog = (char*)"Add User[%s] to %s with %s.";
constexpr char* kRemoveUserLog = (char*)"Remove User[%s] from %s.";

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
  std::sprintf(kAddUserLog, user.GetEmail(), user.GetInboundTag(), user.GetUuid());
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
  std::sprintf(kRemoveUserLog, user.GetEmail(), user.GetInboundTag());
  return true;
}

inline grpc::Status HandlerServiceClient::AlterInbound(
    const v2ray::core::app::proxyman::command::AlterInboundRequest& alter_inbound_request) {
  grpc::ClientContext context;
  v2ray::core::app::proxyman::command::AlterInboundResponse alter_inbound_response;

  return stub_->AlterInbound(&context, alter_inbound_request, &alter_inbound_response);
}

}  // namespace v2m::client
