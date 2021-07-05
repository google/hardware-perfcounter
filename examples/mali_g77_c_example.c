#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "hpc/gpu/mali/driver_ioctl.h"

static void *allocate(void *user_data, size_t size) { return malloc(size); }
static void deallocate(void *user_data, void *memory) { return free(memory); }

int main() {
  int gpu_device = hpc_gpu_mali_ioctl_open_gpu_device();
  if (gpu_device < 0) return perror("open GPU device"), gpu_device;

  // First negotiate API version with the kernel driver. Feeding in 0.0 means to
  // accept whatever version the kernel driver is at, as it does not really
  // matter for us. But we still need to perform this step because the kernel
  // driver needs to initialize API version inside.
  uint16_t major_version = 0, minor_version = 0;
  int status = hpc_gpu_mali_ioctl_setup_api_version(gpu_device, &major_version,
                                                    &minor_version);
  if (gpu_device < 0) return perror("setup API version"), gpu_device;

  printf("Kernel API version: %" PRIu16 ".%" PRIu16 "\n", major_version,
         minor_version);

  // Then setup the kernel API context. This is also necessary for future
  // interactions with the kernel driver.
  status = hpc_gpu_mali_ioctl_setup_api_context(gpu_device);
  if (gpu_device < 0) return perror("setup API context"), gpu_device;

  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};

  hpc_gpu_mali_ioctl_gpu_device_info_t device_info;
  status = hpc_gpu_mali_ioctl_get_gpu_device_info(gpu_device, &allocator,
                                                  &device_info);
  if (gpu_device < 0) return perror("query GPU information"), gpu_device;

  printf("Product ID: %d\nCore mask: %d\nL2 slice count: %d\n",
         device_info.gpu_product_id, device_info.shader_core_mask,
         device_info.num_l2_slices);

  status = hpc_gpu_mali_ioctl_close_gpu_device(gpu_device);
  if (gpu_device < 0) return perror("close GPU device"), status;

  return 0;
}
