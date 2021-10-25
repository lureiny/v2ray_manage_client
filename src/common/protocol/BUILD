load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "user_cc_proto",
    protos = ["user"],
    deps = [
        "//src/common/serial:typed_message_cc_proto",
    ],
)

proto_library(
    name = "user",
    srcs = ["user.proto"],
    deps = [
        "//src/common/serial:typed_message",
    ],
)

cc_proto_library(
    name = "headers_cc_proto",
    deps = [
        "headers",
    ],
)

proto_library(
    name = "headers",
    srcs = ["headers.proto"],
)
