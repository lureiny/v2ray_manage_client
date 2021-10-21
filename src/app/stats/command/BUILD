load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "command_cc_proto",
    deps = [":command"],
)

proto_library(
    name = "command",
    srcs = ["command.proto"],
)
