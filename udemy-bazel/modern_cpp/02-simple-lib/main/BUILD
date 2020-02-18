cc_library(
    name = "SearchBar",
    srcs = ["searchbar/src/SearchBar.cc"],
    hdrs = [
        "searchbar/include/searchbar/SearchBar.h"
    ],
    includes = [
        "searchbar/include"
    ],
    deps = [
        "//lib/calc:Calculator"
    ]
)

cc_binary(
    name = "Main",
    srcs = ["Main.cc"],
    deps = [
        ":SearchBar"
    ],
)
