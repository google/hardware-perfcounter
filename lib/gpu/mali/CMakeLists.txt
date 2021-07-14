hpc_cc_library(
  NAME
    common
  PUBLIC_HDRS
    common.h
  SRCS
    common.c
  PRIVATE_DEPS
    ::context
)

hpc_cc_library(
  NAME
    valhall
  PUBLIC_HDRS
    valhall.h
  SRCS
    valhall.c
  PRIVATE_DEPS
    ::context
)

hpc_cc_library(
  NAME
    bifrost
  PUBLIC_HDRS
    bifrost.h
  SRCS
    bifrost.c
  PRIVATE_DEPS
    ::context
)

hpc_cc_library(
  NAME
    driver-ioctl
  SRCS
    driver_ioctl.h
    driver_ioctl.c
)

hpc_cc_library(
  NAME
    context
  SRCS
    context.h
    context.c
  PRIVATE_DEPS
    ::driver-ioctl
)

