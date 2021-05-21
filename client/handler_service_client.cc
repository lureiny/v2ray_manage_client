#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "app/proxyman/command/command.grpc.pb.h"
#include "proxy/vmess/account.pb.h"
#include "proxy/vless/account.pb.h"

#include "handler_service_client.hpp"

using namespace std;
using namespace v2ray::core::proxy;
using namespace v2ray::core::proxy;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using v2ray::core::app::proxyman::command::AddUserOperation;
using v2ray::core::app::proxyman::command::AlterInboundRequest;
using v2ray::core::app::proxyman::command::AlterInboundResponse;
using v2ray::core::app::proxyman::command::HandlerService;
using v2ray::core::app::proxyman::command::RemoveUserOperation;
using v2ray::core::common::protocol::AUTO;
using v2ray::core::common::protocol::SecurityConfig;
using v2ray::core::common::protocol::User;
using v2ray::core::common::serial::TypedMessage;

HandlerServiceClient::HandlerServiceClient(std::shared_ptr<Channel> channel)
    : _stub(HandlerService::NewStub(channel))
{
}

bool HandlerServiceClient::AddUser(const string &tag, string &email, const string &protocol, const string &uuid)
{
    AddUserOperation add_user_operation;
    if (!this->_MakeAddUserOperation(&add_user_operation, email, protocol, uuid))
    {
        // TODO 抛出异常
        return false;
    }

    TypedMessage operation;
    operation.set_value(add_user_operation.SerializeAsString());
    operation.set_type(ADD_USER_OPERATION_TYPE);

    this->alter_inbound_request.set_tag(tag);
    this->alter_inbound_request.set_allocated_operation(&operation);

    return this->_AlterInbound();
}

bool HandlerServiceClient::_MakeAddUserOperation(AddUserOperation *add_user_operation, const string &email, const string &protocol, const string &id)
{
    TypedMessage *user_account = new TypedMessage;
    if (protocol.compare(PROTOCOL_VMESS) == 0)
    {
        user_account->set_type(VMESS_USER_TYPE);
        vmess::Account account;
        account.set_id(id);
        user_account->set_value(account.SerializeAsString());
    }
    else if (protocol.compare(PROTOCOL_VLESS) == 0)
    {
        user_account->set_type(VLESS_USER_TYPE);
        vless::Account account;
        account.set_id(id);
        user_account->set_value(account.SerializeAsString());
    }
    else
    {
        // TODO 定义一些异常类型
        return false;
    }

    User *user = new User;
    user->set_email(email);
    user->set_level(0);
    user->set_allocated_account(user_account);

    add_user_operation->set_allocated_user(user);
    return true;
}

bool HandlerServiceClient::RemoveUser(const string &tag, const string &email)
{
    RemoveUserOperation remove_user_operation;
    remove_user_operation.set_email(email);

    TypedMessage operation;
    operation.set_type(REMOVE_USER_OPERATION_TYPE);
    operation.set_value(remove_user_operation.SerializeAsString());

    alter_inbound_request.set_tag(tag);
    alter_inbound_request.set_allocated_operation(&operation);
    return _AlterInbound();
}

bool HandlerServiceClient::_AlterInbound()
{
    ClientContext context;
    AlterInboundResponse alter_inbound_response;
    Status status = _stub->AlterInbound(&context, alter_inbound_request, &alter_inbound_response);
    if (status.ok())
    {
        if (alter_inbound_request.operation().type().compare(ADD_USER_OPERATION_TYPE) == 0)
        {
            AddUserOperation add_user_operation;
            add_user_operation.ParseFromString(alter_inbound_request.operation().value());
            cout << "Add User[Email]: " << add_user_operation.user().email() << ", ";
            if (add_user_operation.user().account().type() == VMESS_USER_TYPE) {
                vmess::Account account;
                account.ParseFromString(add_user_operation.user().account().value());
                cout << account.id() << endl;
            }
            else if (add_user_operation.user().account().type() == VLESS_USER_TYPE) {
                vless::Account account;
                account.ParseFromString(add_user_operation.user().account().value());
                cout << account.id() << endl;
            }
            
        }
        else if (alter_inbound_request.operation().type().compare(REMOVE_USER_OPERATION_TYPE) == 0)
        {
            RemoveUserOperation remove_user_operation;
            remove_user_operation.ParseFromString(alter_inbound_request.operation().value());
            cout << "Remove User[Email]: " << remove_user_operation.email() << endl;
        }
        alter_inbound_request.release_operation();        
    }
    else
    {
        cout << status.error_message() << endl;
        alter_inbound_request.release_operation();
        return false;
    }
    return true;
}