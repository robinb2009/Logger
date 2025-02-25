package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "logger",
    srcs = ["logger.cc"],
    hdrs = ["logger.h"],
)

cc_library(
    name = "log_record",
    srcs = ["log_record.cc"],
    hdrs = ["log_record.h"],
)

cc_test(
    name = "test",
    srcs = ["test.cc"],
)
