package(default_visibility = ["//visibility:public"])

# gtest import test
cc_test(
    name = "gtest_test",
    srcs = ["gtest_test.cc"],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "build-all-the-files",
    hdrs = glob(["src/**/*.h"]),
)
