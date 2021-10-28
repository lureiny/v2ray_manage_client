cc_library(
    name = "stat",
    hdrs = ["stat.h"],
    deps = [
        "//src/app/stats/command:command_cc_proto",
    ],
)

cc_test(
    name = "stat_test",
    srcs = ["stat_test.cc"],
    deps = [
        "stat",
        "//src/app/stats/command:command_cc_proto",
        "@gtest//:gtest_main",
    ],
)
