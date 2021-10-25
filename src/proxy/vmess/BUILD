load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_library(
    name = "account_cc_proto",
    protos = ["account"],
    deps = [
        "//src/common/protocol:headers_cc_proto",
    ],
)

proto_library(
    name = "account",
    srcs = ["account.proto"],
    deps = [
        "//src/common/protocol:headers",
    ],
)
