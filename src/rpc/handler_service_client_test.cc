#include "src/rpc/handler_service_client.h"

#include <gmock/gmock.h>
// #include <grpcpp/channel.h>
// #include <grpcpp/create_channel.h>
// #include <grpcpp/security/credentials.h>
#include <gtest/gtest.h>

#include "src/app/proxyman/command/command_mock.grpc.pb.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vmess/account.pb.h"
#include "src/user.h"

namespace v2m::client {

TEST(HandlerServiceClientT, AddUser) {
  v2ray::core::app::proxyman::command::MockHandlerServiceStub* stub =
      new v2ray::core::app::proxyman::command::MockHandlerServiceStub;
  HandlerServiceClient handler(stub);
  EXPECT_CALL(*stub, AlterInbound(::testing::_, ::testing::_, ::testing::_)).WillOnce(testing::Return(grpc::Status()));

  v2ray::core::proxy::vmess::Account vmess_account;
  vmess_account.set_id("76562e1a-730d-4fd8-bc36-4913edcd028f");
  v2m::user::User<v2ray::core::proxy::vmess::Account> user("test", "76562e1a-730d-4fd8-bc36-4913edcd028f", "vmess");
  handler.AddUser(user);
}
}  // namespace v2m::client
