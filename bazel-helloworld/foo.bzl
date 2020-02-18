def foo_impl(repository_ctx):
  rslt = repository_ctx.execute(["echo", "foo"])
  rslt = repository_ctx.execute(["touch", "foo"])
  print("output: %s" % rslt.stdout)


def foo(name, visibility=None):
  print("debugprint")

  localrepo = repository_rule(
      implementation = foo_impl,
      local = True,
      )
  
  native.cc_library(
    # Mental note, this doesn't make a separate .so or .a library.
    # It seems to just link another .o
    name = name,
    srcs = [ "main2.cpp", "main2.h" ],
    visibility = visibility
  )
