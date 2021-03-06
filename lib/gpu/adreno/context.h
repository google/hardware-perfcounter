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

#ifndef HPC_GPU_ADRENO_CONTEXT_H_
#define HPC_GPU_ADRENO_CONTEXT_H_

#include <stdint.h>

#include "driver_ioctl.h"
#include "hpc/gpu/base_utilities.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/// Adreno GPU series.
typedef enum hpc_gpu_adreno_series_e {
  HPC_GPU_ADRENO_SERIES_UNKNOWN,
  /// Adreno A6XX GPUs ((>= 600 && < 700) || == 702)
  HPC_GPU_ADRENO_SERIES_A6XX,
  /// Adreno A5XX GPUs (>= 500 && < 600)
  HPC_GPU_ADRENO_SERIES_A5XX,
} hpc_gpu_adreno_series_t;

/// Returns which series the current GPU in system is.
///
/// @param[in] gpu_id The GPU ID (e.g., 540, 650, etc.)
hpc_gpu_adreno_series_t hpc_gpu_adreno_get_series(int gpu_id);

/// Adreno counter sampling context.
typedef struct hpc_gpu_adreno_context_t {
  /// The list of counters to sample.
  hpc_gpu_adreno_ioctl_counter_read_counter_t *counters;
  /// The previous sampled values of counters.
  uint64_t *prev_values;
  /// The number of counters.
  uint32_t num_counters;
  /// The current GPU's ID.
  uint32_t gpu_id;
  /// THe current GPU's file descriptor.
  int gpu_device;
} hpc_gpu_adreno_context_t;

/// Creates a context for Adreno GPU counters.
///
/// Note that this function performs necessary allocation for counters, but it
/// won't decode the `counters` into their groups and selectors. The caller is
/// expected to additionally do that.
///
/// @param[in]  num_counters The number of counters to sample later.
/// @param[in]  counters     The pointer to the list of counters to sample
///                          later.
/// @param[in]  allocator    The allocator used to allocate host memory for
///                          sampling counters later.
/// @param[out] out_context  The pointer to the object receiving the resultant
///                          context.
int hpc_gpu_adreno_create_context(
    uint32_t num_counters, uint32_t *counters,
    const hpc_gpu_host_allocation_callbacks_t *allocator,
    hpc_gpu_adreno_context_t **out_context);

/// Destroys the context for Adreno GPU counters.
///
/// @param[in] context   The counter sampling context.
/// @param[in] allocator The allocator used to free allocated host memory.
int hpc_gpu_adreno_destroy_context(
    hpc_gpu_adreno_context_t *context,
    const hpc_gpu_host_allocation_callbacks_t *allocator);

/// Starts sampling Adreno GPU counters specified when creating the context.
///
/// This activates the registered counters and reads their initial values in
/// preparation for continously sampling.
///
/// @param[in] context The counter sampling context.
int hpc_gpu_adreno_context_start_counters(
    const hpc_gpu_adreno_context_t *context);

/// Stops sampling Adreno GPU counters specified when creating the context.
///
/// This deactivates the registered counters.
///
/// @param[in] context The counter sampling context.
int hpc_gpu_adreno_context_stop_counters(
    const hpc_gpu_adreno_context_t *context);

/// Samples Adreno GPU counters specified when creating the context.
///
/// @param[in]  context The counter sampling context.
/// @param[out] values  The pointer to the memory for receiving newly sampled
///                     values. Its element count should be greater than or
///                     equal to the number of counters specified when
///                     creating the `context`.
int hpc_gpu_adreno_context_query_counters(hpc_gpu_adreno_context_t *context,
                                          uint64_t *values);

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // HPC_GPU_ADRENO_CONTEXT_H_
