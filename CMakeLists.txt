cmake_minimum_required(VERSION 3.13...3.20)

#===------------------------------------------------------------------------===#
# Overall project settings
#===------------------------------------------------------------------------===#

project(HardwarePerfCounter LANGUAGES C CXX)

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

include(hpc_utils)
include(hpc_cc_library)
include(hpc_cc_binary)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
# Utility tools
#===------------------------------------------------------------------------===#

add_subdirectory(scripts)
