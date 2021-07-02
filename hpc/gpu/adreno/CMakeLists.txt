hpc_cc_library(
  NAME
    a5xx
  HDRS
    a5xx.h
  SRCS
    a5xx.c
)

hpc_cc_library(
  NAME
    a6xx
  HDRS
    a6xx.h
  SRCS
    a6xx.c
)

hpc_cc_library(
  NAME
    common
  HDRS
    common.h
  SRCS
    common.c
  LINKOPTS
    ::driver_ioctl
)

hpc_cc_library(
  NAME
    driver_ioctl
  HDRS
    driver_ioctl.h
  SRCS
    driver_ioctl.c
)
