cc_library(
    name = "handler_service_client",
    # srcs = ["handler_service_client.cc"],
    hdrs = ["handler_service_client.h"],
    deps = [
        "//src:my_user",
        "//src/app/proxyman/command:command_cc_grpc_proto",
        "//src/app/proxyman/operation:alter_inbound_operation",
        "//src/common/protocol:user_cc_proto",
        "//src/common/serial:typed_message_cc_proto",
        "//src/proxy/vless:account_cc_proto",
        "//src/proxy/vmess:account_cc_proto",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_test(
    name = "handler_service_client_test",
    srcs = ["handler_service_client_test.cc"],
    deps = [
        "handler_service_client",
        "//src/proxy/vmess:account_cc_proto",
        "@com_github_grpc_grpc//:grpc++",
        "@gtest//:gtest_main",
    ],
)
