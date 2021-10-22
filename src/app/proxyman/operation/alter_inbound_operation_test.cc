#include "src/app/proxyman/operation/alter_inbound_operation.h"

#include "gtest/gtest.h"
#include "src/app/proxyman/command/command.pb.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vmess/account.pb.h"
#include "src/user.h"

// namespace v2m::test {
TEST(alter_inbound_operation_test, add_user_operation) {
  // 新构建方法
  v2m::user::User<v2ray::core::proxy::vmess::Account> user("test", "76562e1a-730d-4fd8-bc36-4913edcd028f", "vmess");
  v2ray::core::common::protocol::User* vmess_user = new v2ray::core::common::protocol::User;
  user.InsertUserInfoToUserProtobuf(vmess_user);

  // 构建typed_operation
  v2m::operation::AlterInboundOperation<v2ray::core::app::proxyman::command::AddUserOperation> alter_inbound_operation;
  alter_inbound_operation.InsertDataToOpeartion(vmess_user);

  v2ray::core::common::serial::TypedMessage* typed_operation = new v2ray::core::common::serial::TypedMessage;
  alter_inbound_operation.InsertDataToTypedInboundOperation(typed_operation);

  // 原始构建方法
  v2ray::core::common::protocol::User* vmess_user1 = new v2ray::core::common::protocol::User;
  user.InsertUserInfoToUserProtobuf(vmess_user1);
  // 构建typed_operation
  v2ray::core::common::serial::TypedMessage* typed_operation1 = new v2ray::core::common::serial::TypedMessage;
  typed_operation1->set_type("v2ray.core.app.proxyman.command.AddUserOperation");
  v2ray::core::app::proxyman::command::AddUserOperation add_user_operation;
  add_user_operation.set_allocated_user(vmess_user1);

  typed_operation1->set_value(add_user_operation.SerializeAsString());

  EXPECT_EQ(typed_operation->SerializeAsString(), typed_operation1->SerializeAsString());
}

TEST(alter_inbound_operation_test, remove_user_operation) {
  // 基于AlterInboundOperation实例构建
  v2m::operation::AlterInboundOperation<v2ray::core::app::proxyman::command::RemoveUserOperation>
      alter_inbound_operation;
  alter_inbound_operation.InsertDataToOpeartion("vmess_user_test_remove");

  v2ray::core::common::serial::TypedMessage* typed_operation = new v2ray::core::common::serial::TypedMessage;
  alter_inbound_operation.InsertDataToTypedInboundOperation(typed_operation);

  // 原始构建方法
  v2ray::core::app::proxyman::command::RemoveUserOperation remove_user_operation;
  remove_user_operation.set_email("vmess_user_test_remove");
  v2ray::core::common::serial::TypedMessage* typed_operation1 = new v2ray::core::common::serial::TypedMessage;
  alter_inbound_operation.InsertDataToTypedInboundOperation(typed_operation1);
  typed_operation1->set_value(remove_user_operation.SerializeAsString());
  typed_operation1->set_type("v2ray.core.app.proxyman.command.RemoveUserOperation");

  EXPECT_EQ(typed_operation->SerializeAsString(), typed_operation1->SerializeAsString());
}
// }  // namespace v2m::test
