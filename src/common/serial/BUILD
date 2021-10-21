load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "typed_message_cc_proto",
    deps = [":typed_message"],
)

proto_library(
    name = "typed_message",
    srcs = ["typed_message.proto"],
)
