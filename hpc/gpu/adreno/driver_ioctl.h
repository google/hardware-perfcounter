#ifndef HPC_GPU_ADRENO_DRIVER_IOCTL_H_
#define HPC_GPU_ADRENO_DRIVER_IOCTL_H_

#include <stdint.h>

int adreno_open_gpu_device(void);

int adreno_close_gpu_device(int gpu_device);

uint32_t adreno_get_gpu_device_id(int gpu_device);

int andreno_activate_perfcounter(int gpu_device, uint32_t group_id,
                                 uint32_t countable_selector);

int andreno_deactivate_perfcounter(int gpu_device, uint32_t group_id,
                                   uint32_t countable_selector);

typedef struct adreno_perfcounter_read_counter_t {
  uint32_t group_id;
  uint32_t countable_selector;
  uint64_t value;
} adreno_perfcounter_read_counter_t;

int adreno_query_perfcounters(int gpu_device, uint32_t num_counters,
                              adreno_perfcounter_read_counter_t *counters,
                              uint64_t *values);

#endif  // HPC_GPU_ADRENO_DRIVER_IOCTL_H_
