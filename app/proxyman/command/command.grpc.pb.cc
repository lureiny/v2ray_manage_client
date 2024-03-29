// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: app/proxyman/command/command.proto

#include "app/proxyman/command/command.pb.h"
#include "app/proxyman/command/command.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace v2ray {
namespace core {
namespace app {
namespace proxyman {
namespace command {

static const char* HandlerService_method_names[] = {
  "/v2ray.core.app.proxyman.command.HandlerService/AddInbound",
  "/v2ray.core.app.proxyman.command.HandlerService/RemoveInbound",
  "/v2ray.core.app.proxyman.command.HandlerService/AlterInbound",
  "/v2ray.core.app.proxyman.command.HandlerService/AddOutbound",
  "/v2ray.core.app.proxyman.command.HandlerService/RemoveOutbound",
  "/v2ray.core.app.proxyman.command.HandlerService/AlterOutbound",
};

std::unique_ptr< HandlerService::Stub> HandlerService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HandlerService::Stub> stub(new HandlerService::Stub(channel));
  return stub;
}

HandlerService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_AddInbound_(HandlerService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RemoveInbound_(HandlerService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AlterInbound_(HandlerService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddOutbound_(HandlerService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RemoveOutbound_(HandlerService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AlterOutbound_(HandlerService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HandlerService::Stub::AddInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest& request, ::v2ray::core::app::proxyman::command::AddInboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::AddInboundRequest, ::v2ray::core::app::proxyman::command::AddInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddInbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::AddInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest* request, ::v2ray::core::app::proxyman::command::AddInboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::AddInboundRequest, ::v2ray::core::app::proxyman::command::AddInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddInbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::AddInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest* request, ::v2ray::core::app::proxyman::command::AddInboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddInbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AddInboundResponse>* HandlerService::Stub::PrepareAsyncAddInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::AddInboundResponse, ::v2ray::core::app::proxyman::command::AddInboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddInbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AddInboundResponse>* HandlerService::Stub::AsyncAddInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddInboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HandlerService::Stub::RemoveInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest& request, ::v2ray::core::app::proxyman::command::RemoveInboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::RemoveInboundRequest, ::v2ray::core::app::proxyman::command::RemoveInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RemoveInbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::RemoveInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveInboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::RemoveInboundRequest, ::v2ray::core::app::proxyman::command::RemoveInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveInbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::RemoveInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveInboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveInbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::RemoveInboundResponse>* HandlerService::Stub::PrepareAsyncRemoveInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::RemoveInboundResponse, ::v2ray::core::app::proxyman::command::RemoveInboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RemoveInbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::RemoveInboundResponse>* HandlerService::Stub::AsyncRemoveInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRemoveInboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HandlerService::Stub::AlterInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest& request, ::v2ray::core::app::proxyman::command::AlterInboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::AlterInboundRequest, ::v2ray::core::app::proxyman::command::AlterInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AlterInbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::AlterInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest* request, ::v2ray::core::app::proxyman::command::AlterInboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::AlterInboundRequest, ::v2ray::core::app::proxyman::command::AlterInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AlterInbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::AlterInbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest* request, ::v2ray::core::app::proxyman::command::AlterInboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AlterInbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AlterInboundResponse>* HandlerService::Stub::PrepareAsyncAlterInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::AlterInboundResponse, ::v2ray::core::app::proxyman::command::AlterInboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AlterInbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AlterInboundResponse>* HandlerService::Stub::AsyncAlterInboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAlterInboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HandlerService::Stub::AddOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest& request, ::v2ray::core::app::proxyman::command::AddOutboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::AddOutboundRequest, ::v2ray::core::app::proxyman::command::AddOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddOutbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::AddOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest* request, ::v2ray::core::app::proxyman::command::AddOutboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::AddOutboundRequest, ::v2ray::core::app::proxyman::command::AddOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddOutbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::AddOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest* request, ::v2ray::core::app::proxyman::command::AddOutboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddOutbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AddOutboundResponse>* HandlerService::Stub::PrepareAsyncAddOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::AddOutboundResponse, ::v2ray::core::app::proxyman::command::AddOutboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddOutbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AddOutboundResponse>* HandlerService::Stub::AsyncAddOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddOutboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HandlerService::Stub::RemoveOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest& request, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::RemoveOutboundRequest, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RemoveOutbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::RemoveOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::RemoveOutboundRequest, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveOutbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::RemoveOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RemoveOutbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::RemoveOutboundResponse>* HandlerService::Stub::PrepareAsyncRemoveOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::RemoveOutboundResponse, ::v2ray::core::app::proxyman::command::RemoveOutboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RemoveOutbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::RemoveOutboundResponse>* HandlerService::Stub::AsyncRemoveOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRemoveOutboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HandlerService::Stub::AlterOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest& request, ::v2ray::core::app::proxyman::command::AlterOutboundResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::v2ray::core::app::proxyman::command::AlterOutboundRequest, ::v2ray::core::app::proxyman::command::AlterOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AlterOutbound_, context, request, response);
}

void HandlerService::Stub::experimental_async::AlterOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest* request, ::v2ray::core::app::proxyman::command::AlterOutboundResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::v2ray::core::app::proxyman::command::AlterOutboundRequest, ::v2ray::core::app::proxyman::command::AlterOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AlterOutbound_, context, request, response, std::move(f));
}

void HandlerService::Stub::experimental_async::AlterOutbound(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest* request, ::v2ray::core::app::proxyman::command::AlterOutboundResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AlterOutbound_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AlterOutboundResponse>* HandlerService::Stub::PrepareAsyncAlterOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::v2ray::core::app::proxyman::command::AlterOutboundResponse, ::v2ray::core::app::proxyman::command::AlterOutboundRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AlterOutbound_, context, request);
}

::grpc::ClientAsyncResponseReader< ::v2ray::core::app::proxyman::command::AlterOutboundResponse>* HandlerService::Stub::AsyncAlterOutboundRaw(::grpc::ClientContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAlterOutboundRaw(context, request, cq);
  result->StartCall();
  return result;
}

HandlerService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::AddInboundRequest, ::v2ray::core::app::proxyman::command::AddInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::AddInboundRequest* req,
             ::v2ray::core::app::proxyman::command::AddInboundResponse* resp) {
               return service->AddInbound(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::RemoveInboundRequest, ::v2ray::core::app::proxyman::command::RemoveInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::RemoveInboundRequest* req,
             ::v2ray::core::app::proxyman::command::RemoveInboundResponse* resp) {
               return service->RemoveInbound(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::AlterInboundRequest, ::v2ray::core::app::proxyman::command::AlterInboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::AlterInboundRequest* req,
             ::v2ray::core::app::proxyman::command::AlterInboundResponse* resp) {
               return service->AlterInbound(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::AddOutboundRequest, ::v2ray::core::app::proxyman::command::AddOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::AddOutboundRequest* req,
             ::v2ray::core::app::proxyman::command::AddOutboundResponse* resp) {
               return service->AddOutbound(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::RemoveOutboundRequest, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest* req,
             ::v2ray::core::app::proxyman::command::RemoveOutboundResponse* resp) {
               return service->RemoveOutbound(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HandlerService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HandlerService::Service, ::v2ray::core::app::proxyman::command::AlterOutboundRequest, ::v2ray::core::app::proxyman::command::AlterOutboundResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HandlerService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::v2ray::core::app::proxyman::command::AlterOutboundRequest* req,
             ::v2ray::core::app::proxyman::command::AlterOutboundResponse* resp) {
               return service->AlterOutbound(ctx, req, resp);
             }, this)));
}

HandlerService::Service::~Service() {
}

::grpc::Status HandlerService::Service::AddInbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::AddInboundRequest* request, ::v2ray::core::app::proxyman::command::AddInboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HandlerService::Service::RemoveInbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::RemoveInboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveInboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HandlerService::Service::AlterInbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::AlterInboundRequest* request, ::v2ray::core::app::proxyman::command::AlterInboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HandlerService::Service::AddOutbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::AddOutboundRequest* request, ::v2ray::core::app::proxyman::command::AddOutboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HandlerService::Service::RemoveOutbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::RemoveOutboundRequest* request, ::v2ray::core::app::proxyman::command::RemoveOutboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HandlerService::Service::AlterOutbound(::grpc::ServerContext* context, const ::v2ray::core::app::proxyman::command::AlterOutboundRequest* request, ::v2ray::core::app::proxyman::command::AlterOutboundResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace v2ray
}  // namespace core
}  // namespace app
}  // namespace proxyman
}  // namespace command

