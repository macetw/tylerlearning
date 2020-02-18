cc_library(
    name = "Calculator",
    srcs = glob(["src/*.cc"]),
    hdrs = glob(["src/*.h"]),
    includes = ["src"],
    visibility = ["//visibility:public"]
)

cc_test (
    name = "CalculatorTest",
    srcs = [
        "test/CalculatorTest.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":Calculator"
    ]
)
