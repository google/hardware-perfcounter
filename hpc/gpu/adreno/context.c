#include "hpc/gpu/adreno/context.h"

#include <stdint.h>
#include <string.h>  // For memset
#include <unistd.h>  // For close

#include "hpc/gpu/base_utilities.h"

hpc_gpu_adreno_series_t hpc_gpu_adreno_get_series(int gpu_id) {
  if ((gpu_id >= 600 && gpu_id < 700) || gpu_id == 702)
    return HPC_GPU_ADRENO_SERIES_A6XX;
  if (gpu_id >= 500 && gpu_id < 600) return HPC_GPU_ADRENO_SERIES_A5XX;
  return HPC_GPU_ADRENO_SERIES_UNKNOWN;
}

int hpc_gpu_adreno_create_context(
    uint32_t num_counters, uint32_t *counters,
    const hpc_gpu_host_allocation_callbacks_t *allocator,
    hpc_gpu_adreno_context_t **out_context) {
  hpc_gpu_adreno_context_t *context =
      allocator->alloc(allocator->user_data, sizeof(hpc_gpu_adreno_context_t));

  size_t counter_size =
      num_counters * sizeof(hpc_gpu_adreno_ioctl_counter_read_counter_t);
  context->counters = allocator->alloc(allocator->user_data, counter_size);
  memset(context->counters, 0, counter_size);

  size_t init_value_size = num_counters * sizeof(uint64_t);
  context->prev_values =
      allocator->alloc(allocator->user_data, init_value_size);
  memset(context->prev_values, 0, init_value_size);

  context->num_counters = num_counters;

  int gpu_device = hpc_gpu_adreno_ioctl_open_gpu_device();
  if (gpu_device < 0) return gpu_device;
  context->gpu_device = gpu_device;

  uint32_t gpu_id = hpc_gpu_adreno_ioctl_get_gpu_device_id(context->gpu_device);
  if (gpu_id < 0) return gpu_id;
  context->gpu_id = gpu_id;

  *out_context = context;
  return 0;
}

int hpc_gpu_adreno_destroy_context(
    hpc_gpu_adreno_context_t *context,
    const hpc_gpu_host_allocation_callbacks_t *allocator) {
  int status = close(context->gpu_device);
  if (status < 0) return status;

  allocator->free(allocator->user_data, context->prev_values);
  allocator->free(allocator->user_data, context->counters);
  allocator->free(allocator->user_data, context);
  return 0;
}

int hpc_gpu_adreno_context_start_counters(hpc_gpu_adreno_context_t *context) {
  // Activate all selected counters
  hpc_gpu_adreno_series_t series = hpc_gpu_adreno_get_series(context->gpu_id);
  switch (series) {
    case HPC_GPU_ADRENO_SERIES_UNKNOWN:
      // Context creation should guard against this so it should not happen
      // here.
      return 0;
    case HPC_GPU_ADRENO_SERIES_A6XX:
      for (int i = 0; i < context->num_counters; ++i) {
        int status = hpc_gpu_adreno_ioctl_activate_counter(
            context->gpu_device, context->counters[i].group_id,
            context->counters[i].countable_selector);
        if (status < 0) return status;
      }
      break;
    case HPC_GPU_ADRENO_SERIES_A5XX:
      for (int i = 0; i < context->num_counters; ++i) {
        int status = hpc_gpu_adreno_ioctl_activate_counter(
            context->gpu_device, context->counters[i].group_id,
            context->counters[i].countable_selector);
        if (status < 0) return status;
      }
      break;
  }

  // Query their initial values
  int status = hpc_gpu_adreno_ioctl_query_counters(
      context->gpu_device, context->num_counters, context->counters,
      context->prev_values);
  if (status < 0) return status;

  return 0;
}

int hpc_gpu_adreno_context_stop_counters(hpc_gpu_adreno_context_t *context) {
  hpc_gpu_adreno_series_t series = hpc_gpu_adreno_get_series(context->gpu_id);
  switch (series) {
    case HPC_GPU_ADRENO_SERIES_UNKNOWN:
      // Context creation should guard against this so it should not happen
      // here.
      return 0;
    case HPC_GPU_ADRENO_SERIES_A6XX:
      for (int i = 0; i < context->num_counters; ++i) {
        int status = hpc_gpu_adreno_ioctl_deactivate_counter(
            context->gpu_device, context->counters[i].group_id,
            context->counters[i].countable_selector);
        if (status < 0) return status;
      }
      break;
    case HPC_GPU_ADRENO_SERIES_A5XX:
      for (int i = 0; i < context->num_counters; ++i) {
        int status = hpc_gpu_adreno_ioctl_deactivate_counter(
            context->gpu_device, context->counters[i].group_id,
            context->counters[i].countable_selector);
        if (status < 0) return status;
      }
      break;
  }
  return 0;
}

int hpc_gpu_adreno_context_query_counters(hpc_gpu_adreno_context_t *context,
                                          uint64_t *values) {
  int status = hpc_gpu_adreno_ioctl_query_counters(
      context->gpu_device, context->num_counters, context->counters, values);
  for (int i = 0; i < context->num_counters; ++i) {
    uint64_t value = values[i];
    uint64_t prev_value = context->prev_values[i];
    // Counters increase linearly. We need to subtract the previous value.
    if (value < prev_value) return -HPC_GPU_ERROR_INTERNAL;
    values[i] -= prev_value;
    context->prev_values[i] = value;
  }

  if (status < 0) return status;
  return 0;
}
