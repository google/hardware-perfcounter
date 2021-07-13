#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpc/gpu/base_utilities.h"
#include "hpc/gpu/mali/common.h"

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
  hpc_gpu_mali_common_counter_t counters[] = {
      HPC_GPU_MALI_COMMON_JOB_MANAGER_GPU_ACTIVE,
      HPC_GPU_MALI_COMMON_MEMORY_L2_ANY_LOOKUP,
      HPC_GPU_MALI_COMMON_MEMORY_L2_EXT_READ,
      HPC_GPU_MALI_COMMON_MEMORY_L2_EXT_WRITE,
      HPC_GPU_MALI_COMMON_SHADER_CORE_COMPUTE_ACTIVE,
      HPC_GPU_MALI_COMMON_SHADER_CORE_COMPUTE_TASKS,
  };

  uint32_t num_counters = sizeof(counters) / sizeof(counters[0]);

  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};

  hpc_gpu_mali_context_t *context = NULL;
  int status = hpc_gpu_mali_common_create_context(num_counters, counters,
                                                  &allocator, &context);
  if (status < 0) return print_error(status, "crate context");

  status = hpc_gpu_mali_common_start_counters(context);
  if (status < 0) return print_error(status, "start counters");

  uint64_t values[num_counters];

  struct timespec sleep_time, remaining_time;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 100000000;  // 100ms

  for (int i = 0; i < 100; ++i) {
    status = hpc_gpu_mali_common_query_counters(context, values);
    if (status < 0) return print_error(status, "sample GPU counters");
    printf("  jm-busy=%" PRId64 ", l2-lookup=%" PRId64
           ", l2-miss=[read=%" PRId64 ", write=%" PRId64
           "], compute-active=%" PRId64 ", compute-tasks=%" PRId64 "\n",
           values[0], values[1], values[2], values[3], values[4], values[5]);
    nanosleep(&sleep_time, &remaining_time);
  }

  status = hpc_gpu_mali_common_stop_counters(context);
  if (status < 0) return print_error(status, "stop counters");

  status = hpc_gpu_mali_common_destroy_context(context, &allocator);
  if (status < 0) return print_error(status, "destory context");

  return 0;
}
