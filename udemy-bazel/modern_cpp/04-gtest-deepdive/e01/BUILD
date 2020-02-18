cc_library(
    name = "SimpleMath",
    srcs = ["src/SimpleMath.cc"],
    hdrs = ["src/SimpleMath.h"],
    includes = ["src"]
)

cc_test (
    name = "SimpleMathTest",
    srcs = [
        "test/SimpleMathTest.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":SimpleMath"
    ]
)
