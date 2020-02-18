cc_library(
    name = "SearchBar",
    srcs = [
        "src/searchbar/SearchBar.cc"
    ],
    hdrs = [
        "src/searchbar/SearchBar.h"
    ],
    includes = ["src"],
    deps = [
        "//lib/calc:Calculator"
    ]
)

cc_test (
    name = "SearchBarTest",
    srcs = [
        "test/SearchBarTest.cc"
    ],
    timeout="short",
    deps = [
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        ":SearchBar"
    ]
)

cc_binary(
    name = "Main",
    srcs = ["src/Main.cc"],
    deps = [
        ":SearchBar"
    ],
)
