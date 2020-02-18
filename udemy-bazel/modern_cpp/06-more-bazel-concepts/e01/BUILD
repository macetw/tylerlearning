cc_library(
    name = "GreeterDebug",
    hdrs = glob(["include/**/*.h"]),
    srcs = ["src/GreeterDebug.cc"],
    includes = ["include"]
)

cc_library(
    name = "GreeterProduction",
    hdrs = glob(["include/**/*.h"]),
    srcs = ["src/GreeterProduction.cc"],
    includes = ["include"]
)

cc_library(
    name = "GreeterLocal",
    hdrs = glob(["include/**/*.h"]),
    srcs = ["src/GreeterLocal.cc"],
    includes = ["include"]
)

cc_library(
    name = "GreeterDefault",
    hdrs = glob(["include/**/*.h"]),
    srcs = ["src/GreeterDefault.cc"],
    includes = ["include"]
)

cc_binary(
    name = "Main",
    srcs = ["src/Main.cc"],
    deps = 
    select({
        ":debug": [":GreeterDebug"],
        ":production": [":GreeterProduction"],
        ":localDevelopment": [":GreeterLocal"],
        "//conditions:default": [":GreeterDefault"]
    })
)

config_setting(
    name = "debug",
    values = {
        "compilation_mode": "dbg"
    }
)

config_setting(
    name = "production",
    define_values = {
        "type": "production"
    }
)

config_setting(
    name = "localDevelopment",
    values = {
        "compilation_mode": "dbg"
    },
    define_values = {
        "type": "local"
    }
)
