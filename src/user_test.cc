#include "src/user.h"

#include "gtest/gtest.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vless/account.pb.h"
#include "src/proxy/vmess/account.pb.h"

TEST(user_test, my_user) {
  // Test vmess user.
  v2ray::core::proxy::vmess::Account vmess_account;
  vmess_account.set_id("76562e1a-730d-4fd8-bc36-4913edcd028f");
  v2m::user::User<v2ray::core::proxy::vmess::Account> user1("test", "76562e1a-730d-4fd8-bc36-4913edcd028f", "vmess");
  EXPECT_EQ(user1.GetUuid(), "76562e1a-730d-4fd8-bc36-4913edcd028f");
  EXPECT_EQ(user1.GetEmail(), "test");
  EXPECT_EQ(user1.GetInboundTag(), "vmess");
  EXPECT_EQ(user1.GetAccountType(), "v2ray.core.proxy.vmess.Account");
  EXPECT_EQ(user1.GetAccount().SerializeAsString(), vmess_account.SerializeAsString());

  // Test vless user.
  v2ray::core::proxy::vless::Account vless_account;
  vless_account.set_id("76562e1a-730d-4fd8-bc36-4913edcd028f");
  v2m::user::User<v2ray::core::proxy::vless::Account> user2("test", "76562e1a-730d-4fd8-bc36-4913edcd028f", "vless");
  EXPECT_EQ(user2.GetUuid(), "76562e1a-730d-4fd8-bc36-4913edcd028f");
  EXPECT_EQ(user2.GetEmail(), "test");
  EXPECT_EQ(user2.GetInboundTag(), "vless");
  EXPECT_EQ(user2.GetAccountType(), "v2ray.core.proxy.vless.Account");
  EXPECT_EQ(user2.GetAccount().SerializeAsString(), vless_account.SerializeAsString());

  // Test generate "v2ray::core::common::protocol::User"
  // Insert info by "v2m::user"
  v2ray::core::common::protocol::User* vless_user1 = new v2ray::core::common::protocol::User;
  user2.InsertUserInfoToUserProtobuf(vless_user1);

  // Insert info by userself.
  v2ray::core::common::protocol::User vless_user2;
  vless_user2.set_level(0);
  vless_user2.set_email("test");
  v2ray::core::common::serial::TypedMessage* typed_account1 = new v2ray::core::common::serial::TypedMessage;
  typed_account1->set_type("v2ray.core.proxy.vless.Account");
  typed_account1->set_value(vless_account.SerializeAsString());
  vless_user2.set_allocated_account(typed_account1);

  EXPECT_EQ(vless_user2.SerializeAsString(), vless_user1->SerializeAsString());

  // Test generate "v2ray::core::common::protocol::User"
  // Insert info by "v2m::user"
  v2ray::core::common::protocol::User* vmess_user1 = new v2ray::core::common::protocol::User;
  user1.InsertUserInfoToUserProtobuf(vmess_user1);

  // Insert info by userself.
  v2ray::core::common::protocol::User vmess_user2;
  vmess_user2.set_level(0);
  vmess_user2.set_email("test");
  v2ray::core::common::serial::TypedMessage* typed_account2 = new v2ray::core::common::serial::TypedMessage;
  typed_account2->set_type("v2ray.core.proxy.vmess.Account");
  typed_account2->set_value(vmess_account.SerializeAsString());
  vmess_user2.set_allocated_account(typed_account2);

  EXPECT_EQ(vmess_user2.SerializeAsString(), vmess_user1->SerializeAsString());
}