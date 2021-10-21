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
