load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "config_cc_proto",
    protos = ["config"],
    deps = [
        "//src/common/serial:typed_message_cc_proto",
    ],
)

proto_library(
    name = "config",
    srcs = ["config.proto"],
    deps = [
        "//src/common/serial:typed_message",
    ],
)
