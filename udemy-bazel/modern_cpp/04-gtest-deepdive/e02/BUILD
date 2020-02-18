cc_library(
    name = "Stack",
    srcs = ["src/Stack.cc"],
    hdrs = ["src/Stack.h"],
    includes = ["src"]
)

cc_test (
    name = "StackTest",
    srcs = [
        "test/StackTest.cc",
        "test/InheritedStackTest.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":Stack"
    ]
)
