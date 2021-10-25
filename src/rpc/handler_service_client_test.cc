
#include "src/rpc/handler_service_client.h"

#include <grpcpp/security/credentials.h>

#include "gtest/gtest.h"
#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vless/account.pb.h"
#include "src/proxy/vmess/account.pb.h"
#include "src/user.h"

TEST(1, 1) {
  HandlerServiceClient handler(grpc::CreateChannel("127.0.0.1:1080", grpc::InsecureChannelCredentials()));
  v2ray::core::proxy::vmess::Account vmess_account;
  vmess_account.set_id("76562e1a-730d-4fd8-bc36-4913edcd028f");
  v2m::user::User<v2ray::core::proxy::vmess::Account> user("test", "76562e1a-730d-4fd8-bc36-4913edcd028f", "vmess");
  handler.AddUser(user);
}