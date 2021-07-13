#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpc/gpu/mali/driver_ioctl.h"

static void *allocate(void *user_data, size_t size) { return malloc(size); }
static void deallocate(void *user_data, void *memory) { return free(memory); }

int print_error(int status, char *message) {
  if (-status >= HPC_GPU_FIRST_ERROR_CODE) {
    printf("error %d: %s\n", status, message);
  } else {
    perror(message);
  }
  return status;
}

int main() {
  int gpu_device = hpc_gpu_mali_ioctl_open_gpu_device();
  if (gpu_device < 0) return print_error(gpu_device, "open GPU device");

  // First negotiate API version with the kernel driver. Feeding in 0.0 means to
  // accept whatever version the kernel driver is at, as it does not really
  // matter for us. But we still need to perform this step because the kernel
  // driver needs to initialize API version inside.
  uint16_t major_version = 0, minor_version = 0;
  int status = hpc_gpu_mali_ioctl_setup_api_version(gpu_device, &major_version,
                                                    &minor_version);
  if (status < 0) return print_error(status, "setup API version");

  printf("Kernel API version: %" PRIu16 ".%" PRIu16 "\n", major_version,
         minor_version);

  // Then setup the kernel API context. This is also necessary for future
  // interactions with the kernel driver.
  status = hpc_gpu_mali_ioctl_setup_api_context(gpu_device);
  if (status < 0) return print_error(status, "setup API context");

  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};

  hpc_gpu_mali_ioctl_gpu_device_info_t device_info;
  status = hpc_gpu_mali_ioctl_get_gpu_device_info(gpu_device, &allocator,
                                                  &device_info);
  if (status < 0) return print_error(status, "query GPU information");

  printf("Product ID: %d\nCore mask: %d\nL2 slice count: %d\n",
         device_info.gpu_product_id, device_info.shader_core_mask,
         device_info.num_l2_slices);

  hpc_gpu_mali_ioctl_counter_reader_t counter_reader;
  status = hpc_gpu_mali_ioctl_open_counter_reader(gpu_device, &counter_reader);
  if (status < 0) return print_error(status, "get counter reader");

  printf("Single buffer size: %d\n", counter_reader.single_buffer_size);

  uint32_t *values = malloc(counter_reader.single_buffer_size);

  struct timespec sleep_time, remaining_time;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 100000000;  // 100ms

  for (int i = 0; i < 100; ++i) {
    uint64_t timestamp = 0;
    status =
        hpc_gpu_mali_ioctl_query_counters(&counter_reader, values, &timestamp);
    if (status < 0) return print_error(status, "sample GPU counters");

    printf("Timestamp: %" PRIu64 "\n", timestamp);
    for (int j = 0; j < 10; ++j) printf("  %d", values[j]);
    printf("\n");

    nanosleep(&sleep_time, &remaining_time);
  }

  free(values);

  status = hpc_gpu_mali_ioctl_close_counter_reader(&counter_reader);
  if (status < 0) return print_error(status, "close counter reader");

  status = hpc_gpu_mali_ioctl_close_gpu_device(gpu_device);
  if (status < 0) return print_error(status, "close GPU device");

  return 0;
}
