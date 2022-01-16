/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HPC_GPU_ALLOCATION_CALLBACK_H_
#define HPC_GPU_ALLOCATION_CALLBACK_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/// Error codes used by this library.
///
/// This library is a low-level library that directly talks with GPU Kernel
/// drivers, which indicates errors with known errno. So errors specific
/// to this library follows similar scheme, but using large error numbers
/// to avoid overlap with the kernel.
typedef enum hpc_gpu_error_e {
  /// The first error code used by this library.
  HPC_GPU_FIRST_ERROR_CODE = 1000,
  /// The current GPU device is unknown.
  HPC_GPU_ERROR_UNKNOWN_DEVICE = HPC_GPU_FIRST_ERROR_CODE,
  /// The current GPU device is incompatible.
  HPC_GPU_ERROR_INCOMPATIBLE_DEVICE,
  /// The connection with driver was terminated.
  HPC_GPU_ERROR_DRIVER_HUNGUP,
  /// Internal error.
  HPC_GPU_ERROR_INTERNAL,
} hpc_gpu_error_t;

/// Pointer to host memory allocation function.
typedef void* (*hpc_gpu_host_alloc_function)(void* user_data, size_t size);
/// Pointer to host memory free function.
typedef void (*hpc_gpu_host_free_function)(void* user_data, void* memory);

/// Struct containing host memory allocation/free functions.
typedef struct hpc_gpu_host_allocation_callbacks_t {
  /// User data that will be passed to `alloc`/`free`.
  void* user_data;
  hpc_gpu_host_alloc_function alloc;
  hpc_gpu_host_free_function free;
} hpc_gpu_host_allocation_callbacks_t;

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // HPC_GPU_ALLOCATION_CALLBACK_H_
