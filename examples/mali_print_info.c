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

#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MALI_IOCTL_TYPE 0x80

struct mali_device_api_version {
  uint16_t major;
  uint16_t minor;
};

#define MALI_IOCTL_VERSION_HANDSHAKE \
  _IOWR(MALI_IOCTL_TYPE, 0, struct mali_device_api_version)

#define MALI_CONTEXT_DISABLE_SUBMISSION (1u << 1)

struct mali_context_set_creation_flags {
  uint32_t flags;
};

#define MALI_IOCTL_SET_CONTEXT_CREATION_FLAGS \
  _IOW(MALI_IOCTL_TYPE, 1, struct mali_context_set_creation_flags)

#define MALI_PROPERTY_PRODUCT_ID 1
#define MALI_PROPERTY_VERSION_STATUS 2
#define MALI_PROPERTY_MINOR_REVISION 3
#define MALI_PROPERTY_MAJOR_REVISION 4
#define MALI_PROPERTY_GPU_FREQ_KHZ_MAX 6
#define MALI_PROPERTY_GPU_AVAILABLE_MEMORY_SIZE 12
#define MALI_PROPERTY_L2_LOG2_LINE_SIZE 13
#define MALI_PROPERTY_L2_LOG2_CACHE_SIZE 14
#define MALI_PROPERTY_L2_NUM_L2_SLICES 15
#define MALI_PROPERTY_MAX_THREADS 18
#define MALI_PROPERTY_MAX_WORKGROUP_SIZE 19
#define MALI_PROPERTY_MAX_BARRIER_SIZE 20
#define MALI_PROPERTY_MAX_REGISTERS 21
#define MALI_PROPERTY_MAX_TASK_QUEUE 22
#define MALI_PROPERTY_MAX_THREAD_GROUP_SPLIT 23
#define MALI_PROPERTY_RAW_GPU_ID 55
#define MALI_PROPERTY_COHERENCY_NUM_GROUPS 61
#define MALI_PROPERTY_COHERENCY_NUM_CORE_GROUPS 62
#define MALI_PROPERTY_COHERENCY_COHERENCY 63

#define MALI_PROPERTY_COHERENCY_GROUP_0 64
#define MALI_PROPERTY_COHERENCY_GROUP_15 79

struct mali_device_properties {
  uint32_t id;
  const char* name;
};

struct mali_device_get_property {
  uint64_t buffer;
  uint32_t buffer_size;
  uint32_t flags;
};

#define MALI_IOCTL_DEVICE_GET_ROPERTY \
  _IOW(MALI_IOCTL_TYPE, 3, struct mali_device_get_property)

int main() {
  int gpu_device = open("/dev/mali0", O_RDWR);
  if (gpu_device < 0) return perror("open GPU device"), gpu_device;

  struct mali_device_api_version api_version = {0, 0};
  int status = ioctl(gpu_device, MALI_IOCTL_VERSION_HANDSHAKE, &api_version);
  if (status < 0) return perror("api version handshake"), status;

  struct mali_context_set_creation_flags flags = {
      MALI_CONTEXT_DISABLE_SUBMISSION};
  status = ioctl(gpu_device, MALI_IOCTL_SET_CONTEXT_CREATION_FLAGS, &flags);
  if (status < 0) return perror("setup api context"), status;

  struct mali_device_get_property properties;
  memset(&properties, 0, sizeof(struct mali_device_get_property));

  int buffer_size =
      ioctl(gpu_device, MALI_IOCTL_DEVICE_GET_ROPERTY, &properties);
  if (buffer_size < 0) return perror("query GPU property size"), buffer_size;

  void* buffer = malloc(buffer_size);
  properties.buffer = (uint64_t)buffer;
  properties.buffer_size = buffer_size;
  status = ioctl(gpu_device, MALI_IOCTL_DEVICE_GET_ROPERTY, &properties);
  if (status < 0) return perror("query GPU property"), status;

  struct mali_device_properties selected_properties[] = {
      {MALI_PROPERTY_PRODUCT_ID, "Product ID"},
      {MALI_PROPERTY_VERSION_STATUS, "Version status"},
      {MALI_PROPERTY_MINOR_REVISION, "Minor revision"},
      {MALI_PROPERTY_MAJOR_REVISION, "Major revision"},
      {MALI_PROPERTY_GPU_FREQ_KHZ_MAX, "Max freqency (kHz)"},
      {MALI_PROPERTY_GPU_AVAILABLE_MEMORY_SIZE, "Available memory size"},
      {MALI_PROPERTY_L2_LOG2_LINE_SIZE, "L2 log2 line size"},
      {MALI_PROPERTY_L2_LOG2_CACHE_SIZE, "L2 log2 cache size"},
      {MALI_PROPERTY_L2_NUM_L2_SLICES, "L2 # slices"},
      {MALI_PROPERTY_MAX_THREADS, "Max threads"},
      {MALI_PROPERTY_MAX_WORKGROUP_SIZE, "Max workgroup size"},
      {MALI_PROPERTY_MAX_BARRIER_SIZE, "Max barrier size"},
      {MALI_PROPERTY_MAX_REGISTERS, "Max registers"},
      {MALI_PROPERTY_MAX_TASK_QUEUE, "Max task queue"},
      {MALI_PROPERTY_MAX_THREAD_GROUP_SPLIT, "Max threadgroup split"},
      {MALI_PROPERTY_RAW_GPU_ID, "GPU ID"},
      {MALI_PROPERTY_COHERENCY_NUM_GROUPS, "Coherency # groups"},
      {MALI_PROPERTY_COHERENCY_NUM_CORE_GROUPS, "Coherency # core groups"},
      {MALI_PROPERTY_COHERENCY_COHERENCY, "Coherency status"},
  };

  uint32_t num_properties =
      sizeof(selected_properties) / sizeof(selected_properties[0]);

  for (uint8_t *buffer_ptr = (uint8_t*)buffer,
               *buffer_end = (uint8_t*)buffer + buffer_size;
       buffer_ptr != buffer_end;) {
    uint32_t key = *(uint32_t*)buffer_ptr;
    buffer_ptr += sizeof(uint32_t);

    uint64_t value = 0;
    uint32_t property_id = key >> 2;
    switch (key & 0x3) {
      case 0:
        value = *buffer_ptr;
        buffer_ptr += 1;
        break;
      case 1:
        value = *(uint16_t*)buffer_ptr;
        buffer_ptr += 2;
        break;
      case 2:
        value = *(uint32_t*)buffer_ptr;
        buffer_ptr += 4;
        break;
      case 3:
        value = *(uint64_t*)buffer_ptr;
        buffer_ptr += 8;
        break;
    }

    for (int i = 0; i < num_properties; ++i) {
      if (selected_properties[i].id == property_id) {
        printf("  %s: %" PRId64 "\n", selected_properties[i].name, value);
      }
    }
    if (MALI_PROPERTY_COHERENCY_GROUP_0 <= property_id &&
        property_id <= MALI_PROPERTY_COHERENCY_GROUP_15) {
      uint32_t group_id = property_id - MALI_PROPERTY_COHERENCY_GROUP_0;
      printf("  Coherency group #%d core mask: %" PRId64 "\n", group_id, value);
    }
  }

  free(buffer);
  status = close(gpu_device);
  if (status < 0) return perror("close GPU device"), gpu_device;

  return 0;
}
