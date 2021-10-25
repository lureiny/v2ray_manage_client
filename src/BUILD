load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "config_cc_proto",
    protos = ["config"],
    deps = [
        "//src/common/serial:typed_message_cc_proto",
        "//src/transport:config_cc_proto",
    ]
)

proto_library(
    name = "config",
    srcs = ["config.proto"],
    deps = [
        "//src/common/serial:typed_message",
        "//src/transport:config",
    ],
)

cc_library(
    name = "my_user",
    hdrs = ["user.h"],
    deps = [
        "//src/common/protocol:user_cc_proto",
        "//src/common/serial:typed_message_cc_proto",
        "//src/proxy/vless:account_cc_proto",
        "//src/proxy/vmess:account_cc_proto",
    ],
)

cc_binary(
    name = "v2m",
    srcs = ["vmc.cc"],
    deps = ["//src:config_cc_proto"],
)

####################################################################

cc_test(
    name = "my_user_test",
    srcs = ["user_test.cc"],
    deps = [
        "my_user",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
