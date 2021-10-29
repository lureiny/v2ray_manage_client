#include "src/rpc_client/base_client.h"

#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "src/app/proxyman/command/command.grpc.pb.h"
#include "src/app/stats/command/command.grpc.pb.h"
#include "src/rpc_client/parameter_strcut.h"
#include "src/rpc_client/stats_service_client.h"

namespace v2m {
namespace client {
constexpr std::string kAddUserOperation{"add_user"};
constexpr std::string kRemoveUserOperation{"remove_user"};
constexpr std::string kVmee{"vmess"};
constexpr std::string kVlee{"vless"};

bool BaseHandlerClient::Init(const InputParameter& input_parameter) {
  host_ = input_parameter.host;

  stub_ = v2ray::core::app::proxyman::command::HandlerService::NewStub(
      grpc::CreateChannel(input_parameter.host, grpc::InsecureChannelCredentials()));
  handler_client_ = new HandlerServiceClient(stub_);
}

bool BaseHandlerClient::RequestRemote(const InputParameter& input_parameter) {
  // TODO user use factory mode to improve.
  if (input_parameter.protocol == kVmess) {
    }
}
}  // namespace client
}  // namespace v2m
