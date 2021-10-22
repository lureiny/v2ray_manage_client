package(default_visibility = ["//visibility:public"])

cc_library(
    name = "alter_inbound_operation",
    hdrs = ["alter_inbound_operation.h"],
)

cc_test(
    name = "alter_inbound_operation_test",
    srcs = ["alter_inbound_operation_test.cc"],
    deps = [
        "alter_inbound_operation",
        "//src:my_user",
        "//src/app/proxyman/command:command_cc_proto",
        "//src/common/protocol:user_cc_proto",
        "//src/common/serial:typed_message_cc_proto",
        "//src/proxy/vmess:account_cc_proto",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
