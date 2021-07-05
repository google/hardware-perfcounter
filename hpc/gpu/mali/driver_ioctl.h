#ifndef HPC_GPU_MALI_DRIVER_IOCTL_H_
#define HPC_GPU_MALI_DRIVER_IOCTL_H_

#include <stdint.h>

#include "hpc/gpu/allocation_callback.h"

int hpc_gpu_mali_ioctl_open_gpu_device(void);

int hpc_gpu_mali_ioctl_close_gpu_device(int gpu_device);

int hpc_gpu_mali_ioctl_setup_api_version(int gpu_device,
                                         uint16_t *major_version,
                                         uint16_t *minor_version);

int hpc_gpu_mali_ioctl_setup_api_context(int gpu_device);

typedef struct hpc_gpu_mali_ioctl_gpu_device_info_t {
  uint32_t gpu_product_id;
  uint32_t shader_core_mask;
  uint32_t num_l2_slices;
} hpc_gpu_mali_ioctl_gpu_device_info_t;

int hpc_gpu_mali_ioctl_get_gpu_device_info(
    int gpu_device, const hpc_gpu_host_allocation_callbacks_t *allocator,
    hpc_gpu_mali_ioctl_gpu_device_info_t *info);

typedef struct hpc_gpu_mali_ioctl_perfcounter_reader_t {
  uint32_t single_buffer_size;
  uint32_t buffer_count;
  uint8_t *whole_kernel_buffer;
  int reader_fd;
} hpc_gpu_mali_ioctl_perfcounter_reader_t;

int hpc_gpu_mali_ioctl_open_perfcounter_reader(
    int gpu_device, hpc_gpu_mali_ioctl_perfcounter_reader_t *counter_reader);

int hpc_gpu_mali_ioctl_close_perfcounter_reader(
    hpc_gpu_mali_ioctl_perfcounter_reader_t *counter_reader);

int hpc_gpu_mali_ioctl_query_perfcounters(
    const hpc_gpu_mali_ioctl_perfcounter_reader_t *counter_reader, void *values,
    uint64_t *timestamp);

#endif  // HPC_GPU_MALI_DRIVER_IOCTL_H_
