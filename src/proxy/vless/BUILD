load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "account_cc_proto",
    deps = [":account"],
)

proto_library(
    name = "account",
    srcs = ["account.proto"],
)
