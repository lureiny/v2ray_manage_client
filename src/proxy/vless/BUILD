load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "account_cc_proto",
    protos = ["account"],
)

proto_library(
    name = "account",
    srcs = ["account.proto"],
)
