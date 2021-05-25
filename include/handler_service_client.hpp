#ifndef HANDLER_SERVICE_CLIENT
#define HANDLER_SERVICE_CLIENT

#include <string>
#include <algorithm>
#include <memory>
#include <grpcpp/channel.h>

#include "app/proxyman/command/command.grpc.pb.h"

const std::string ADD_USER_OPERATION_TYPE = "v2ray.core.app.proxyman.command.AddUserOperation";
const std::string REMOVE_USER_OPERATION_TYPE = "v2ray.core.app.proxyman.command.RemoveUserOperation";
const uint32_t LEVEL = 0;
const std::string PROTOCOL_VLESS = "vless";
const std::string PROTOCOL_VMESS = "vmess";
const std::string PROTOCOL_TROJAN = "trojan";
const std::string VLESS_USER_TYPE = "v2ray.core.proxy.vless.Account";
const std::string VMESS_USER_TYPE = "v2ray.core.proxy.vmess.Account";
const std::string ADD_USER_OPERATION = "add_user";
const std::string REMOVE_USER_OPERATION = "remove_user";

class HandlerServiceClient
{
public:
    HandlerServiceClient(std::shared_ptr<grpc::Channel>);
    bool AddUser(const std::string &, std::string &, const std::string &, const std::string &);
    bool RemoveUser(const std::string &, const std::string &);

private:
    // 创建服务器链接
    std::unique_ptr<v2ray::core::app::proxyman::command::HandlerService::Stub> _stub;

    v2ray::core::app::proxyman::command::AlterInboundRequest alter_inbound_request;

    /*
        创建AddUserOperation
    */
    bool _MakeAddUserOperation(v2ray::core::app::proxyman::command::AddUserOperation *, const std::string &, const std::string &, const std::string &);

    // 更新Inbound
    bool _AlterInbound();
};

#endif