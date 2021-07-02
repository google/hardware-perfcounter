#ifndef HPC_GPU_ADRENO_DRIVER_IOCTL_H_
#define HPC_GPU_ADRENO_DRIVER_IOCTL_H_

#include <stdint.h>

/// Opens the Adreno GPU device in the current system.
int adreno_open_gpu_device(void);

/// Closes the Adreno GPU device.
///
/// @param[in] gpu_device The file descriptor for the GPU device.
int adreno_close_gpu_device(int gpu_device);

/// Gets the Adreno GPU device ID.
///
/// @param[in] gpu_device The file descriptor for the GPU device.
uint32_t adreno_get_gpu_device_id(int gpu_device);

/// Activates an Adreno perfcounter.
///
/// @param[in] gpu_device         The file descriptor for the GPU device.
/// @param[in] group_id           The perfcounter's group ID.
/// @param[in] countable_selector The perfcounter's selector.
int andreno_activate_perfcounter(int gpu_device, uint32_t group_id,
                                 uint32_t countable_selector);

/// Deactivates an Adreno perfcounter.
///
/// @param[in] gpu_device         The file descriptor for the GPU device.
/// @param[in] group_id           The perfcounter's group ID.
/// @param[in] countable_selector The perfcounter's selector.
int andreno_deactivate_perfcounter(int gpu_device, uint32_t group_id,
                                   uint32_t countable_selector);

typedef struct adreno_perfcounter_read_counter_t {
  uint32_t group_id;
  uint32_t countable_selector;
  uint64_t value;
} adreno_perfcounter_read_counter_t;

/// Samples multiple Adreno perfcounters.
///
/// @param[in]  gpu_device   The file descriptor for the GPU device.
/// @param[in]  num_counters The number of counters to sample.
/// @param[in]  counters     The list of counters to sample.
/// @param[out] values       The pointer to memory to receive sampled values.
///                          Its element count should be greater than or
///                          equal to the number of perfcounters specified when
///                          creating the `context`.
int adreno_query_perfcounters(int gpu_device, uint32_t num_counters,
                              adreno_perfcounter_read_counter_t *counters,
                              uint64_t *values);

#endif  // HPC_GPU_ADRENO_DRIVER_IOCTL_H_
