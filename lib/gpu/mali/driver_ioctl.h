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

#ifndef HPC_GPU_MALI_DRIVER_IOCTL_H_
#define HPC_GPU_MALI_DRIVER_IOCTL_H_

#include <stdint.h>

#include "hpc/gpu/base_utilities.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/// Opens the Mali GPU device in the current system.
int hpc_gpu_mali_ioctl_open_gpu_device(void);

/// Closes the given Mali GPU device.
///
/// @param[in] gpu_device The file descriptor for the GPU device.
int hpc_gpu_mali_ioctl_close_gpu_device(int gpu_device);

/// Negotiates kernel driver API version.
///
/// The requested major/minor version should be passed in when calling this
/// function, after returning, `major_verision`/`minor_version` will convey
/// the final chosen version by the driver.
//
/// @param[in]     gpu_device    The file descriptor for the GPU device.
/// @param[in,out] major_version The API major version.
/// @param[in,out] major_version The API minor version.
int hpc_gpu_mali_ioctl_setup_api_version(int gpu_device,
                                         uint16_t *major_version,
                                         uint16_t *minor_version);

/// Sets up the kernel driver API context.
///
/// This should be called after API version negotiation and before sending
/// other requests to the kernel driver.
///
/// @param[in] gpu_device The file descriptor for the GPU device.
int hpc_gpu_mali_ioctl_setup_api_context(int gpu_device);

/// Mali GPU device information.
typedef struct hpc_gpu_mali_ioctl_gpu_device_info_t {
  /// GPU product ID (only the lower 16-bit is meaningful).
  uint32_t gpu_product_id;
  /// Mask indicating which shader core is active.
  uint32_t shader_core_mask;
  /// The number of available L2 cache slices.
  uint32_t num_l2_slices;
} hpc_gpu_mali_ioctl_gpu_device_info_t;

/// Gets the Mali GPU device information.
///
/// @param[in]  gpu_device The file descriptor for the GPU device.
/// @param[in]  allocator  Allocator for managing host memory.
/// @param[out] info       Mali GPU device information.
int hpc_gpu_mali_ioctl_get_gpu_device_info(
    int gpu_device, const hpc_gpu_host_allocation_callbacks_t *allocator,
    hpc_gpu_mali_ioctl_gpu_device_info_t *info);

/// Mali GPU counter reader information.
///
/// Upon request from a user space application, the kernel driver allocates
/// multiple buffers to form a ring buffer for serving counter sample requests
/// from the user space. Each buffer has a size to contain *all* counters.
typedef struct hpc_gpu_mali_ioctl_counter_reader_t {
  /// The size of a single buffer in a ring buffer.
  uint32_t single_buffer_size;
  /// The number of buffers in the ring buffer.
  uint32_t buffer_count;
  /// The pointer to mmapped kernel buffer.
  uint8_t *whole_kernel_buffer;
  /// The counter reader's file descriptor.
  int reader_fd;
} hpc_gpu_mali_ioctl_counter_reader_t;

/// Opens a Mali GPU counter reader.
///
/// For Mali GPUs, querying the counters goes through another API surface,
/// instead of using the main GPU device file descriptor.
///
/// @param[in]  gpu_device     The file descriptor for the GPU device.
/// @param[out] counter_reader Counter reader's information.
int hpc_gpu_mali_ioctl_open_counter_reader(
    int gpu_device, hpc_gpu_mali_ioctl_counter_reader_t *counter_reader);

/// Closes the given counter reader.
int hpc_gpu_mali_ioctl_close_counter_reader(
    const hpc_gpu_mali_ioctl_counter_reader_t *counter_reader);

/// Zeros all counters in the given counter reader.
int hpc_gpu_mali_ioctl_zero_counters(
    const hpc_gpu_mali_ioctl_counter_reader_t *counter_reader);

/// Samples all Mali counters.
///
/// This samples all available counters on the GPU and returns them via
/// `values`. It's the caller's responsibility to extract the interesting
/// counters.
///
/// @param[in]  counter_reader The Mali GPU counter reader's information.
/// @param[out] values         The pointer to recipient buffer for one sample.
/// @param[out] timestamp      THe timestamp for the sampling.
int hpc_gpu_mali_ioctl_query_counters(
    const hpc_gpu_mali_ioctl_counter_reader_t *counter_reader, uint32_t *values,
    uint64_t *timestamp);

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // HPC_GPU_MALI_DRIVER_IOCTL_H_
