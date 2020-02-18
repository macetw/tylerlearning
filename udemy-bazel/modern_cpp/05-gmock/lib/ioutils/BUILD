cc_library(
    name = "IOUtils",
    srcs = glob(["src/*.cc"]),
    hdrs = glob(["include/**/*.h"]),
    includes = [
        "include"
    ],
    linkopts = [
        "-lstdc++fs"
    ],
    visibility = ["//visibility:public"]
)

cc_test (
    name = "IOUtilsTest",
    srcs = [
        "test/IOUtilsTest.cc",
        "test/MockIOUtils.h",
        "test/MockDive.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":IOUtils"
    ]
)
