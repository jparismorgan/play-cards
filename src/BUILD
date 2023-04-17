load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_test(
    size = "small",
    name = "card-test",
    srcs = [
        "card-test.cc"
    ],
    deps = [
        ":card",
        "@googletest//:gtest_main",
    ]
)

cc_library(
    name = "card",
    hdrs = [
        "card.h"
    ],
)

cc_test(
    size = "small",
    name = "game-test",
    srcs = [
        "game-test.cc"
    ],
    deps = [
        ":game",
        "@googletest//:gtest_main",
    ]
)

cc_library(
    name = "game",
    hdrs = [
        "game.h"
    ],
    srcs = [
        "game.cc"
    ],
    deps = [
        ":player",
        ":card",
        ":log",
    ]
)

cc_test(
    size = "small",
    name = "log-test",
    srcs = [
        "log-test.cc"
    ],
    deps = [
        ":log",
        "@googletest//:gtest_main",
    ]
)

cc_library(
    name = "log",
    hdrs = [
        "log.h"
    ],
    srcs = [
        "log.cc"
    ],
)

cc_binary(
    name = "play-game",
    srcs = [
        "play-game.cc",
    ],
    deps = [
        ":log",
        ":game",
    ]
)

cc_test(
    size = "small",
    name = "player-test",
    srcs = [
        "player-test.cc"
    ],
    deps = [
        ":player",
        "@googletest//:gtest_main",
    ]
)

cc_library(
    name = "player",
    hdrs = [
        "player.h"
    ],
    srcs = [
        "player.cc"
    ],
    deps = [
        ":card",
        ":log",
    ]
)

