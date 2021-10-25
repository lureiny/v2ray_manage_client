load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "command_cc_proto",
    protos = ["command"],
)

proto_library(
    name = "command",
    srcs = ["command.proto"],
)

cpp_grpc_library(
    name = "command_cc_grpc_proto",
    protos = ["command"],
)
