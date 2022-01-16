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

cmake_minimum_required(VERSION 3.13...3.20)

#===------------------------------------------------------------------------===#
# Overall project settings
#===------------------------------------------------------------------------===#

project(HardwarePerfCounter VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#===------------------------------------------------------------------------===#
# Overall functionality controls
#===------------------------------------------------------------------------===#

option(HPC_ENABLE_GPU_ADRENO "Enable support for Qualcomm Adreno GPUs" ON)
option(HPC_ENABLE_GPU_MALI   "Enable support for ARM Mali GPUs" ON)

option(HPC_BUILD_EXAMPLES "Build usage example binaries" ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#===------------------------------------------------------------------------===#
# CMake definitions
#===------------------------------------------------------------------------===#

set(HPC_SOURCE_ROOT "${PROJECT_SOURCE_DIR}")

set(HPC_DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Missing CMAKE_BUILD_TYPE; using '${HPC_DEFAULT_BUILD_TYPE}'")
  set(CMAKE_BUILD_TYPE "${HPC_DEFAULT_BUILD_TYPE}"
    CACHE STRING "CMake build type" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH ${HPC_SOURCE_ROOT}/cmake)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(hpc_utils)
include(hpc_cc_library)
include(hpc_cc_binary)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#===------------------------------------------------------------------------===#
# Headers
#===------------------------------------------------------------------------===#

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#===------------------------------------------------------------------------===#
# Libraries
#===------------------------------------------------------------------------===#

if(HPC_ENABLE_GPU_ADRENO)
  add_subdirectory(lib/gpu/adreno)
endif()
if(HPC_ENABLE_GPU_MALI)
  add_subdirectory(lib/gpu/mali)
endif()
if(HPC_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

#===------------------------------------------------------------------------===#
# Installation and export
#===------------------------------------------------------------------------===#

set(HPC_CMAKE_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

# Install a *Config.cmake file containing all the libraries so that downstream
# users can use `find_package` to discover this package.
install(
  EXPORT hpc-lib-targets
  FILE "${PROJECT_NAME}Config.cmake"
  DESTINATION "${HPC_CMAKE_INSTALL_DIR}"
)

# Export the same *Config.cmake file from the build tree to allow downstream
# users to discover this package directly from the build tree.
export(EXPORT hpc-lib-targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
)

# Create the *ConfigVersion.cmake file. It can be used by `find_package` to
# handle versions.
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMinorVersion
)

# Install the *ConfigVersion.cmake file.
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION "${HPC_CMAKE_INSTALL_DIR}"
)

# Register into the User Package Registry. With this, users can build and
# register this package in the build tree via
#   cmake -DCMAKE_EXPORT_PACKAGE_REGISTRY=ON
# when invoking CMake. Afterwards, calling `find_package(HardwarePerfCounter)`
# in the downstream application will just work.
export(PACKAGE ${PROJECT_NAME})

#===------------------------------------------------------------------------===#
# Utility tools
#===------------------------------------------------------------------------===#

add_subdirectory(scripts EXCLUDE_FROM_ALL)
