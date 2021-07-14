#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpc/gpu/adreno/a6xx.h"
#include "hpc/gpu/base_utilities.h"

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

int main(void) {
  hpc_gpu_adreno_a6xx_counter_t counters[] = {
      HPC_GPU_ADRENO_A6XX_SP_BUSY_CYCLES,
      HPC_GPU_ADRENO_A6XX_SP_VS_INSTRUCTIONS,
      HPC_GPU_ADRENO_A6XX_SP_FS_INSTRUCTIONS,
      HPC_GPU_ADRENO_A6XX_SP_CS_INSTRUCTIONS,
      HPC_GPU_ADRENO_A6XX_SP_GPR_READ_CONFLICT,   // A6XX specific
      HPC_GPU_ADRENO_A6XX_SP_GPR_WRITE_CONFLICT,  // A6XX specific
  };

  uint32_t num_counters = sizeof(counters) / sizeof(counters[0]);

  hpc_gpu_adreno_context_t *context = NULL;
  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};
  int status = hpc_gpu_adreno_a6xx_create_context(num_counters, counters,
                                                  &allocator, &context);
  if (status < 0) return print_error(status, "create context");

  status = hpc_gpu_adreno_a6xx_start_counters(context);
  if (status < 0) return print_error(status, "start counters");

  uint64_t values[num_counters];

  struct timespec sleep_time, remaining_time;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 100000000;  // 100ms

  for (int i = 0; i < 100; ++i) {
    hpc_gpu_adreno_a6xx_query_counters(context, values);
    printf("  sp-busy-cycles=%" PRId64 ", sp-instructions=[vs=%" PRId64
           ", fs=%" PRId64 ", cs=%" PRId64 "], sp-gpr-conflict=[load=%" PRId64
           ", store=%" PRId64 "]\n",
           values[0], values[1], values[2], values[3], values[4], values[5]);

    nanosleep(&sleep_time, &remaining_time);
  }

  status = hpc_gpu_adreno_a6xx_stop_counters(context);
  if (status < 0) return print_error(status, "stop counters");

  status = hpc_gpu_adreno_a6xx_destroy_context(context, &allocator);
  if (status < 0) return print_error(status, "destroy context");

  return 0;
}
