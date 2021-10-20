#pragma once

#include <string>
#include <type_traits>

#include "app/proxyman/command/command.pb.h"
#include "common/serial/typed_message.pb.h"

namespace v2m::operation {
constexpr char* kAddUserOperation =
    "v2ray.core.app.proxyman.command.AddUserOperation";
constexpr char* kRemoveUserOperation =
    "v2ray.core.app.proxyman.command.RemoveUserOperation";

// Operation should be "v2ray::core::app::proxyman::command::AddUserOperation"
// or "v2ray::core::app::proxyman::command::RemoveUserOperation"
template <typename Operation>
class AlterInboundOperation : v2ray::core::common::serial::TypedMessage {
  static_assert(
      std::is_same<
          Operation,
          v2ray::core::app::proxyman::command::AddUserOperation>::value ||
      std::is_same<
          Operation,
          v2ray::core::app::proxyman::command::RemoveUserOperation>::value);

 public:
  AlterInboundOperation(const Operation& operation) {
    set_value(operation.SerializeAsString());
    if (std::is_same<
            Operation,
            v2ray::core::app::proxyman::command::AddUserOperation>::value) {
      set_type(kAddUserOperation);
    } else {
      set_type(kRemoveUserOperation);
    }
  };
};
}  // namespace v2m::operation
