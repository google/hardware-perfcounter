#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpc/gpu/adreno/common.h"
#include "hpc/gpu/adreno/driver_ioctl.h"
#include "hpc/gpu/base_utilities.h"

static void *allocate(void *user_data, size_t size) { return malloc(size); }
static void deallocate(void *user_data, void *memory) { return free(memory); }

int main(void) {
  int gpu_device = hpc_gpu_adreno_ioctl_open_gpu_device();
  if (gpu_device < 0) perror("open GPU device");

  int gpu_id = hpc_gpu_adreno_ioctl_get_gpu_device_id(gpu_device);
  if (gpu_id < 0) perror("query GPU ID");
  printf("[GPU] Adreno %d\n", gpu_id);

  int status = hpc_gpu_adreno_ioctl_close_gpu_device(gpu_device);
  if (status < 0) perror("close GPU device");

  hpc_gpu_adreno_common_perfcounter_t perfcounters[] = {
      HPC_GPU_ADRENO_COMMON_SP_BUSY_CYCLES,
      HPC_GPU_ADRENO_COMMON_SP_VS_INSTRUCTIONS,
      HPC_GPU_ADRENO_COMMON_SP_FS_INSTRUCTIONS,
      HPC_GPU_ADRENO_COMMON_SP_CS_INSTRUCTIONS,
      HPC_GPU_ADRENO_COMMON_SP_GM_LOAD_INSTRUCTIONS,
      HPC_GPU_ADRENO_COMMON_SP_GM_STORE_INSTRUCTIONS,
  };

  uint32_t num_counters = sizeof(perfcounters) / sizeof(perfcounters[0]);

  hpc_gpu_adreno_context_t *context = NULL;
  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};
  status = hpc_gpu_adreno_common_create_context(num_counters, perfcounters,
                                                &allocator, &context);
  if (status < 0) {
    if (-status >= HPC_GPU_FIRST_ERROR_CODE) {
      printf("create context error: %d\n", status);
    } else {
      perror("create context");
    }
    return status;
  }

  status = hpc_gpu_adreno_common_start_perfcounters(context);
  if (status < 0) {
    perror("start perfcounters");
    return status;
  }

  uint64_t values[num_counters];

  struct timespec sleep_time, remaining_time;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 100000000;  // 100ms

  for (int i = 0; i < 100; ++i) {
    hpc_gpu_adreno_common_query_perfcounters(context, values);
    printf("  sp-busy-cycles=%" PRId64 ", sp-instructions=[vs=%" PRId64
           ", fs=%" PRId64 ", cs=%" PRId64 "], sp-global-mem=[load=%" PRId64
           ", store=%" PRId64 "]\n",
           values[0], values[1], values[2], values[3], values[4], values[5]);

    nanosleep(&sleep_time, &remaining_time);
  }

  status = hpc_gpu_adreno_common_stop_perfcounters(context);
  if (status < 0) {
    perror("stop perfcounters");
    return status;
  }
  status = hpc_gpu_adreno_common_destroy_context(context, &allocator);
  if (status < 0) {
    perror("destroy context");
    return status;
  }

  return 0;
}
