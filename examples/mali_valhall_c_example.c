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

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hpc/gpu/base_utilities.h"
#include "hpc/gpu/mali/valhall.h"

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
  hpc_gpu_mali_valhall_counter_t counters[] = {
      HPC_GPU_MALI_VALHALL_JOB_MANAGER_GPU_ACTIVE,
      HPC_GPU_MALI_VALHALL_MEMORY_L2_ANY_LOOKUP,
      HPC_GPU_MALI_VALHALL_MEMORY_MMU_HIT_L2,  // Valhall specific
      HPC_GPU_MALI_VALHALL_MEMORY_MMU_HIT_L3,  // Valhall specific
      HPC_GPU_MALI_VALHALL_SHADER_CORE_COMPUTE_ACTIVE,
      HPC_GPU_MALI_VALHALL_SHADER_CORE_EXEC_INSTR_FMA,  // Valhall specific
  };

  uint32_t num_counters = sizeof(counters) / sizeof(counters[0]);

  hpc_gpu_host_allocation_callbacks_t allocator = {NULL, &allocate,
                                                   &deallocate};

  hpc_gpu_mali_context_t *context = NULL;
  int status = hpc_gpu_mali_valhall_create_context(num_counters, counters,
                                                   &allocator, &context);
  if (status < 0) return print_error(status, "crate context");

  status = hpc_gpu_mali_valhall_start_counters(context);
  if (status < 0) return print_error(status, "start counters");

  uint64_t values[num_counters];

  struct timespec sleep_time, remaining_time;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 100000000;  // 100ms

  for (int i = 0; i < 100; ++i) {
    status = hpc_gpu_mali_valhall_query_counters(context, values);
    if (status < 0) return print_error(status, "sample GPU counters");
    printf("  gpu-active=%" PRId64 ", l2-lookup=%" PRId64
           ", mmu-hit=[l2=%" PRId64 ", l3=%" PRId64 "], compute-active=%" PRId64
           ", fma-inst=%" PRId64 "\n",
           values[0], values[1], values[2], values[3], values[4], values[5]);
    nanosleep(&sleep_time, &remaining_time);
  }

  status = hpc_gpu_mali_valhall_stop_counters(context);
  if (status < 0) return print_error(status, "stop counters");

  status = hpc_gpu_mali_valhall_destroy_context(context, &allocator);
  if (status < 0) return print_error(status, "destory context");

  return 0;
}
