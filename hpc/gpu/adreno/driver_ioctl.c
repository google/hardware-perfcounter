#include "hpc/gpu/adreno/driver_ioctl.h"

#include <assert.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ADRENO_IOCTL_TYPE 0x09

// We use explicit-sized data types in APIs, but the kernel uses
// platform-dependent ones. Generally its's fine but just double
// check here.
static_assert(sizeof(uint32_t) == sizeof(unsigned int),
              "32-bit data type size mismatch");
static_assert(sizeof(uint64_t) == sizeof(unsigned long long),
              "64-bit data type size mismatch");

//===----------------------------------------------------------------------===//
// Open/close device
//===----------------------------------------------------------------------===//

int hpc_gpu_adreno_ioctl_open_gpu_device(void) {
  return open("/dev/kgsl-3d0", O_RDWR);
}

int hpc_gpu_adreno_ioctl_close_gpu_device(int gpu_device) {
  return close(gpu_device);
}

//===----------------------------------------------------------------------===//
// Get device information
//===----------------------------------------------------------------------===//

#define ADRENO_PROPERTY_DEVICE_INFO 0x1

struct adreno_device_info {
  unsigned int device_id;
  unsigned int chip_id;
  unsigned int mmu_enabled;
  unsigned long gmem_gpu_base_address;
  unsigned int gpu_id;
  size_t gmem_sizebytes;
};

struct adreno_device_get_property {
  unsigned int type;
  void *value;
  size_t num_bytes;
};

#define ADRENO_IOCTL_DEVICE_GET_PROPERTY \
  _IOWR(ADRENO_IOCTL_TYPE, 0x2, struct adreno_device_get_property)

uint32_t hpc_gpu_adreno_ioctl_get_gpu_device_id(int gpu_device) {
  struct adreno_device_info devinfo;
  memset(&devinfo, 0, sizeof(struct adreno_device_info));

  struct adreno_device_get_property payload;
  payload.type = ADRENO_PROPERTY_DEVICE_INFO;
  payload.value = &devinfo;
  payload.num_bytes = sizeof(struct adreno_device_info);

  int status = ioctl(gpu_device, ADRENO_IOCTL_DEVICE_GET_PROPERTY, &payload);
  if (status < 0) return status;

  uint32_t chip_id = devinfo.chip_id;
  uint8_t core_id = (chip_id >> (8 * 3)) & 0xffu;
  uint8_t major_id = (chip_id >> (8 * 2)) & 0xffu;
  uint8_t minor_id = (chip_id >> (8 * 1)) & 0xffu;
  return core_id * 100 + major_id * 10 + minor_id;
}

//===----------------------------------------------------------------------===//
// Activate counter
//===----------------------------------------------------------------------===//

struct adreno_counter_get {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int regster_offset_low;
  unsigned int regster_offset_high;
  unsigned int __pad;
};

#define ADRENO_IOCTL_COUNTER_GET \
  _IOWR(ADRENO_IOCTL_TYPE, 0x38, struct adreno_counter_get)

int hpc_gpu_adreno_ioctl_activate_counter(int gpu_device, uint32_t group_id,
                                          uint32_t countable_selector) {
  struct adreno_counter_get payload;
  memset(&payload, 0, sizeof(struct adreno_counter_get));
  payload.group_id = group_id;
  payload.countable_selector = countable_selector;

  return ioctl(gpu_device, ADRENO_IOCTL_COUNTER_GET, &payload);
}

//===----------------------------------------------------------------------===//
// Deactivate counter
//===----------------------------------------------------------------------===//

struct adreno_counter_put {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_COUNTER_PUT \
  _IOW(ADRENO_IOCTL_TYPE, 0x39, struct adreno_counter_put)

int hpc_gpu_adreno_ioctl_deactivate_counter(int gpu_device, uint32_t group_id,
                                            uint32_t countable_selector) {
  struct adreno_counter_put payload;
  memset(&payload, 0, sizeof(struct adreno_counter_put));
  payload.group_id = group_id;
  payload.countable_selector = countable_selector;

  return ioctl(gpu_device, ADRENO_IOCTL_COUNTER_PUT, &payload);
}

//===----------------------------------------------------------------------===//
// Query counter
//===----------------------------------------------------------------------===//

struct adreno_counter_read {
  struct hpc_gpu_adreno_ioctl_counter_read_counter_t *counters;
  unsigned int num_counters;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_COUNTER_READ \
  _IOWR(ADRENO_IOCTL_TYPE, 0x3B, struct adreno_counter_read)

int hpc_gpu_adreno_ioctl_query_counters(
    int gpu_device, uint32_t num_counters,
    hpc_gpu_adreno_ioctl_counter_read_counter_t *counters, uint64_t *values) {
  struct adreno_counter_read payload;
  memset(&payload, 0, sizeof(struct adreno_counter_read));
  payload.num_counters = num_counters;
  payload.counters = counters;

  int status = ioctl(gpu_device, ADRENO_IOCTL_COUNTER_READ, &payload);
  if (status) return status;

  for (int i = 0; i < num_counters; ++i) values[i] = counters[i].value;

  return 0;
}
