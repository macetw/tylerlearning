
def foo(name, visibility=None):
  print("debugprint")
  native.cc_library(
    # Mental note, this doesn't make a separate .so or .a library.
    # It seems to just link another .o
    name = name,
    srcs = [ "main2.cpp", "main2.h" ],
    visibility = visibility
  )
