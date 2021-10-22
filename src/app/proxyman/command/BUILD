load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

# cc_library(
#     name = "command_pb",
#     srcs = ["command.pb.cc"],
#     hdrs = ["command.pb.h"],
#     deps = [
#         # ":user_pb",
#         "@com_google_protobuf//:protobuf_headers",
#         "@com_google_protobuf//:protobuf_lite",
#     ],
# )

cc_proto_library(
    name = "command_cc_proto",
    deps = [":command"],
)

proto_library(
    name = "command",
    srcs = ["command.proto"],
    deps = [
        "//src:config",
        "//src/common/protocol:user",
        "//src/common/serial:typed_message",
    ],
)

cc_library(
    name = "command_cc_grpc_proto",
    srcs = ["command.grpc.pb.cc"],
    hdrs = ["command.grpc.pb.h"],
    copts = ["-ldl"],
    deps = [
        "command_cc_proto",
        "@com_github_grpc_grpc//:grpc++",
        # "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)
