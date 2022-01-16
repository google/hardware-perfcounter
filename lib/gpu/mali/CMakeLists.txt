# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

hpc_cc_library(
  NAME
    common
  PUBLIC_HDRS
    common.h
  SRCS
    common.c
  PRIVATE_DEPS
    ::context
  INSTALL_COMPONENT
    MaliGPU
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
  INSTALL_COMPONENT
    MaliGPU
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
  INSTALL_COMPONENT
    MaliGPU
)

hpc_cc_library(
  NAME
    driver-ioctl
  SRCS
    driver_ioctl.h
    driver_ioctl.c
  PRIVATE_INCLUDES
    "${HPC_SOURCE_ROOT}/third_party"
  INSTALL_COMPONENT
    MaliGPU
)

hpc_cc_library(
  NAME
    context
  SRCS
    context.h
    context.c
  PRIVATE_DEPS
    ::driver-ioctl
  INSTALL_COMPONENT
    MaliGPU
)

