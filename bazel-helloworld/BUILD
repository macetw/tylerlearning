# Designed for use with Bazel

load("//:foo.bzl", "foo")

cc_binary(
        name = "helloworld",
              srcs = [ "main.cpp" ],
	        deps = [ "//:helloworldlib" ]
)

foo( name = "helloworldlib" )
 
