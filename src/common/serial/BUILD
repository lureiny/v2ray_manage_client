load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "typed_message_cc_proto",
    protos = ["typed_message"],
)

proto_library(
    name = "typed_message",
    srcs = ["typed_message.proto"],
)
