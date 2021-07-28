/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 */

// Note: this file contains Adreno GPU kernel driver ioctl definitions taken
// from the following files in linux source tree:
//
// [include/uapi/linux/msm_kgsl.h](https://github.com/antiagainst/SM-G991U/blob/main/include/uapi/linux/msm_kgsl.h)
//
// The definitions are modified for clarity and to maintain consistency of the
// project.

#ifndef THIRD_PARTY_LINUX_ADRENO_DRIVER_IOCTL_H_
#define THIRD_PARTY_LINUX_ADRENO_DRIVER_IOCTL_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#define ADRENO_IOCTL_TYPE 0x09

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

struct adreno_counter_get {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int regster_offset_low;
  unsigned int regster_offset_high;
  unsigned int __pad;
};

#define ADRENO_IOCTL_COUNTER_GET \
  _IOWR(ADRENO_IOCTL_TYPE, 0x38, struct adreno_counter_get)

struct adreno_counter_put {
  unsigned int group_id;
  unsigned int countable_selector;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_COUNTER_PUT \
  _IOW(ADRENO_IOCTL_TYPE, 0x39, struct adreno_counter_put)

struct adreno_counter_read {
  struct hpc_gpu_adreno_ioctl_counter_read_counter_t *counters;
  unsigned int num_counters;
  unsigned int __pad[2];
};

#define ADRENO_IOCTL_COUNTER_READ \
  _IOWR(ADRENO_IOCTL_TYPE, 0x3B, struct adreno_counter_read)

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // THIRD_PARTY_LINUX_ADRENO_DRIVER_IOCTL_H_
