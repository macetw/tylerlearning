# Designed for use with Bazel


cc_binary(
        name = "helloworld",
              srcs = [ "main.cpp" ],
	        deps = [ "//:helloworldlib" ]
)

cc_library(
    name = "helloworldlib",
    srcs = [ "main2.cpp", "main2.h" ]
    )
