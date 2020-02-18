cc_library(
    name = "Utils",
    srcs = ["src/Utils.cc"],
    hdrs = ["src/Utils.h"],
    includes = ["src"]
)

cc_test (
    name = "UtilsTest",
    srcs = glob(include = [
        "test/UtilsTest*.cc"
        ],
        exclude = [
            "test/UtilsTest4.cc"
        ]),
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":Utils"
    ]
)

cc_test (
    name = "UtilsTestWithListeners",
    srcs = [
        "test/UtilsTest4.cc",
        "test/TestMain.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        ":Utils"
    ]
)
