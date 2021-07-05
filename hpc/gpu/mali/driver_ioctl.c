#include "hpc/gpu/mali/driver_ioctl.h"

#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "hpc/gpu/allocation_callback.h"

//===----------------------------------------------------------------------===//
// Open/close device
//===----------------------------------------------------------------------===//

int hpc_gpu_mali_ioctl_open_gpu_device(void) {
  return open("/dev/mali0", O_RDWR);
}

int hpc_gpu_mali_ioctl_close_gpu_device(int gpu_device) {
  return close(gpu_device);
}

//===----------------------------------------------------------------------===//
// Setup API
//===----------------------------------------------------------------------===//

#define MALI_IOCTL_TYPE 0x80

struct mali_device_api_version {
  uint16_t major;
  uint16_t minor;
};

#define MALI_IOCTL_VERSION_HANDSHAKE \
  _IOWR(MALI_IOCTL_TYPE, 0, struct mali_device_api_version)

int hpc_gpu_mali_ioctl_setup_api_version(int gpu_device,
                                         uint16_t *major_version,
                                         uint16_t *minor_version) {
  struct mali_device_api_version api_version = {*major_version, *minor_version};

  int status = ioctl(gpu_device, MALI_IOCTL_VERSION_HANDSHAKE, &api_version);
  if (status < 0) return status;

  *major_version = api_version.major;
  *minor_version = api_version.minor;
  return 0;
}

#define MALI_CONTEXT_DISABLE_SUBMISSION (1u << 1)

struct mali_context_set_creation_flags {
  uint32_t flags;
};

#define MALI_IOCTL_SET_CONTEXT_CREATION_FLAGS \
  _IOW(MALI_IOCTL_TYPE, 1, struct mali_context_set_creation_flags)

int hpc_gpu_mali_ioctl_setup_api_context(int gpu_device) {
  struct mali_context_set_creation_flags flags;
  // We just want to sample perfcounters. So disable submission.
  flags.flags = MALI_CONTEXT_DISABLE_SUBMISSION;
  return ioctl(gpu_device, MALI_IOCTL_SET_CONTEXT_CREATION_FLAGS, &flags);
}

//===----------------------------------------------------------------------===//
// Get device information
//===----------------------------------------------------------------------===//

#define MALI_PROPERTY_PRODUCT_ID 1
#define MALI_PROPERTY_NUM_L2_SLICES 15
#define MALI_PROPERTY_COHERENCY_GROUP_0 64
#define MALI_PROPERTY_COHERENCY_GROUP_15 79

struct mali_device_get_property {
  uint64_t buffer;
  uint32_t buffer_size;
  uint32_t flags;
};

#define MALI_IOCTL_DEVICE_GET_ROPERTY \
  _IOW(MALI_IOCTL_TYPE, 3, struct mali_device_get_property)

int hpc_gpu_mali_ioctl_get_gpu_device_info(
    int gpu_device, const hpc_gpu_host_allocation_callbacks_t *allocator,
    hpc_gpu_mali_ioctl_gpu_device_info_t *info) {
  struct mali_device_get_property properties;
  memset(&properties, 0, sizeof(struct mali_device_get_property));

  // First query the size of all properties and allocate such a buffer.
  int buffer_size =
      ioctl(gpu_device, MALI_IOCTL_DEVICE_GET_ROPERTY, &properties);
  void *buffer = allocator->alloc(allocator->user_data, buffer_size);

  // Then get all properties.
  properties.buffer = (uint64_t)buffer;
  properties.buffer_size = buffer_size;
  int status = ioctl(gpu_device, MALI_IOCTL_DEVICE_GET_ROPERTY, &properties);
  if (status < 0) return status;

  // Clear output info struct.
  memset(info, 0, sizeof(hpc_gpu_mali_ioctl_gpu_device_info_t));

  // Now decode the information we need.
  // According to Mali kernel driver documentation, the returned buffer contains
  // packed (key, value) pairs, where the key is
  //   (<property-id> << 2) | <value-type>.
  // where <value-type> can be the following:
  //   0b00: u8, 0b01: u16, 0b10: u32, 0b11: 64
  for (uint8_t *buffer_ptr = (uint8_t *)buffer,
               *buffer_end = (uint8_t *)buffer + buffer_size;
       buffer_ptr != buffer_end;) {
    uint32_t key = *(uint32_t *)buffer_ptr;
    buffer_ptr += sizeof(uint32_t);

    // All the values cannot exceed 64-bit. Use uint64_t here to simplify
    // the logic.
    uint64_t value = 0;
    uint32_t property_id = key >> 2;
    switch (key & 0x3) {
      case 0:
        value = *buffer_ptr;
        buffer_ptr += 1;
        break;
      case 1:
        value = *(uint16_t *)buffer_ptr;
        buffer_ptr += 2;
        break;
      case 2:
        value = *(uint32_t *)buffer_ptr;
        buffer_ptr += 4;
        break;
      case 3:
        value = *(uint64_t *)buffer_ptr;
        buffer_ptr += 8;
        break;
    }

    if (property_id == MALI_PROPERTY_PRODUCT_ID) {
      info->gpu_product_id = (uint32_t)value;
    } else if (property_id == MALI_PROPERTY_NUM_L2_SLICES) {
      info->num_l2_slices = (uint32_t)value;
    } else if (MALI_PROPERTY_COHERENCY_GROUP_0 <= property_id &&
               property_id <= MALI_PROPERTY_COHERENCY_GROUP_15) {
      // Each coherent group contains a few shader cores. We want to know all
      // the available shader cores. So collect them.
      info->shader_core_mask |= (uint32_t)value;
    }
  }

  allocator->free(allocator->user_data, buffer);
  return 0;
}
