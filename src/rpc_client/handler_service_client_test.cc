#include "src/rpc_client/handler_service_client.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "src/app/proxyman/command/command_mock.grpc.pb.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vless/account.pb.h"
#include "src/proxy/vmess/account.pb.h"
#include "src/user.h"

namespace v2m {
namespace client {
class RpcTestInterface : public ::testing::Test {
 protected:
  static void SetUpTestCase() {}

  static void TearDownTestCase() {
    delete RpcTestInterface::handler;
    RpcTestInterface::handler = nullptr;
    RpcTestInterface::stub = nullptr;
  }

 public:
  static v2ray::core::app::proxyman::command::MockHandlerServiceStub* stub;
  static HandlerServiceClient* handler;
};

// Init mock stub, handler client and common user.
v2ray::core::app::proxyman::command::MockHandlerServiceStub* RpcTestInterface::stub =
    new v2ray::core::app::proxyman::command::MockHandlerServiceStub;
HandlerServiceClient* RpcTestInterface::handler = new HandlerServiceClient(RpcTestInterface::stub);

v2m::user::User<v2ray::core::proxy::vmess::Account> vmess_user("vmess_test",
                                                               "76562e1a-730d-4fd8-bc36-4913edcd028f",
                                                               "vmess_inbound");
v2m::user::User<v2ray::core::proxy::vless::Account> vless_user("vless_test",
                                                               "76562e1a-730d-4fd8-bc36-4913edcd028f",
                                                               "vless_inbound");

TEST_F(RpcTestInterface, SuccessfullyAddUser) {
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status()))
      .WillOnce(testing::Return(grpc::Status()));
  // Add vmess user test.
  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->AddUser(vmess_user);
  std::string add_vmess_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(add_vmess_user_output, "Add User[vmess_test] to vmess_inbound with 76562e1a-730d-4fd8-bc36-4913edcd028f.");

  // Add vless user test.
  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->AddUser(vless_user);
  std::string add_vless_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(add_vless_user_output, "Add User[vless_test] to vless_inbound with 76562e1a-730d-4fd8-bc36-4913edcd028f.");
}

TEST_F(RpcTestInterface, SuccessfullyRemoveUser) {
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status()))
      .WillOnce(testing::Return(grpc::Status()));
  // V2ray remove user just by user's email/name.
  // Remove vmess test.
  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->RemoveUser(vmess_user);
  std::string remove_vmess_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(remove_vmess_user_output, "Remove User[vmess_test] from vmess_inbound.");

  // Remove vless test.
  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->RemoveUser(vless_user);
  std::string remove_vless_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(remove_vless_user_output, "Remove User[vless_test] from vless_inbound.");
}

TEST_F(RpcTestInterface, UnsuccessfullyAddUser) {
  // Add exist vmess user test.
  std::string vmess_mock_error_msg("The user " + vmess_user.GetEmail() + " already exist.");
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status(grpc::StatusCode::ALREADY_EXISTS, vmess_mock_error_msg)));

  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->AddUser(vmess_user);
  std::string add_vmess_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(add_vmess_user_output, "The user vmess_test already exist.\n");

  // Add exist vless user test.
  std::string vless_mock_error_msg("The user " + vless_user.GetEmail() + " already exist.");
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status(grpc::StatusCode::ALREADY_EXISTS, vless_mock_error_msg)));

  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->AddUser(vless_user);
  std::string add_vless_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(add_vless_user_output, "The user vless_test already exist.\n");
}

TEST_F(RpcTestInterface, UnsuccessfullyRemoveUser) {
  // Remove not exist vmess user.
  std::string vmess_mock_error_msg("The user " + vmess_user.GetEmail() + " not exist.");
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status(grpc::StatusCode::NOT_FOUND, vmess_mock_error_msg)));

  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->RemoveUser(vmess_user);
  std::string remove_vmess_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(remove_vmess_user_output, "The user vmess_test not exist.\n");

  // Remove not exist vless user.
  std::string vless_mock_error_msg("The user " + vless_user.GetEmail() + " not exist.");
  EXPECT_CALL(*RpcTestInterface::stub, AlterInbound(::testing::_, ::testing::_, ::testing::_))
      .WillOnce(testing::Return(grpc::Status(grpc::StatusCode::NOT_FOUND, vless_mock_error_msg)));

  // Capture the cout.
  ::testing::internal::CaptureStdout();
  handler->RemoveUser(vless_user);
  std::string remove_vless_user_output = ::testing::internal::GetCapturedStdout();
  EXPECT_EQ(remove_vless_user_output, "The user vless_test not exist.\n");
}
}  // namespace client
}  // namespace v2m
