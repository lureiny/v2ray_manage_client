load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "config_cc_proto",
    deps = [":config"],
)

proto_library(
    name = "config",
    srcs = ["config.proto"],
    deps = ["//src/transport/internet:config"],
)
