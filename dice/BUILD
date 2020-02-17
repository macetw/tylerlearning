load("//tools/build_rules:qt.bzl", "qt_cc_library")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
        '-fpic',
    ],
    deps = [
        ":mainwindow",
        "@qt//:qt_widgets",
    ],
)

qt_cc_library(
    name = "dice_by_bazel",
    src = "dicewindow.cpp",
    hdr = "dicewindow.h",
    normal_hdrs = [
        'dice.h'
    ],
    copts = [
        '-fpic',
    ],
    deps = [
        "@qt//:qt_core",
        "@qt//:qt_widgets",
        "@qt//:qt_gui",
    ],
    ui = [ ],
    ui_deps = [
        "@qt//:qt_widgets",
    ],
)
