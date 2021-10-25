#pragma once

#include <type_traits>

#include "src/app/proxyman/command/command.pb.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"

namespace v2m::operation {
constexpr char* kAddUserOperationType = (char*)"v2ray.core.app.proxyman.command.AddUserOperation";
constexpr char* kRemoveUserOperationType = (char*)"v2ray.core.app.proxyman.command.RemoveUserOperation";

// Operation should be "v2ray::core::app::proxyman::command::AddUserOperation"
// or "v2ray::core::app::proxyman::command::RemoveUserOperation"
template <typename Operation>
class AlterInboundOperation {
  static_assert(std::is_same<Operation, v2ray::core::app::proxyman::command::AddUserOperation>::value ||
                std::is_same<Operation, v2ray::core::app::proxyman::command::RemoveUserOperation>::value);

 public:
  AlterInboundOperation() {
    if (std::is_same<Operation, v2ray::core::app::proxyman::command::AddUserOperation>::value) {
      operation_type_ = kAddUserOperationType;
    } else {
      operation_type_ = kRemoveUserOperationType;
    }
  };

  // Insert data to add user operation. This function can be use only when Operation ==
  // "v2ray::core::app::proxyman::command::AddUserOperation"
  inline void InsertDataToOpeartion(v2ray::core::common::protocol::User* user) {
    static_assert(
        std::is_same<Operation, v2ray::core::app::proxyman::command::AddUserOperation>::value,
        "This function can be use only when Operation == \"v2ray::core::app::proxyman::command::AddUserOperation\"");
    operation_.set_allocated_user(user);
  };

  // Insert data to remove user operation.This function can be use only when Operation ==
  // "v2ray::core::app::proxyman::command::RemoveUserOperation"
  inline void InsertDataToOpeartion(const std::string& email) {
    static_assert(
        std::is_same<Operation, v2ray::core::app::proxyman::command::RemoveUserOperation>::value,
        "This function can be use only when Operation == \"v2ray::core::app::proxyman::command::RemoveUserOperation\"");
    operation_.set_email(email);
  };

  inline void InsertDataToTypedInboundOperation(v2ray::core::common::serial::TypedMessage* typed_operation) {
    typed_operation->set_type(operation_type_);
    typed_operation->set_value(operation_.SerializeAsString());
  };

 private:
  std::string operation_type_;
  Operation operation_;
};
}  // namespace v2m::operation
