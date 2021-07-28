/*
 * Copyright (c) 2017-2019 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// Note: this file contains Mali GPU kernel driver ioctl definitions taken from
// the following files in the HWCPipe project:
//
// [vendor/arm/mali/hwc.hpp](https://github.com/ARM-software/HWCPipe/blob/master/vendor/arm/mali/hwc.hpp)
//
// The definitions are modified for clarity and to maintain consistency of the
// project.

#ifndef THIRD_PARTY_LINUX_MALI_DRIVER_IOCTL_H_
#define THIRD_PARTY_LINUX_MALI_DRIVER_IOCTL_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

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

struct mali_counter_reader_setup {
  uint32_t buffer_count;
  uint32_t frontend_bitmask;     // Frontend counter selection bitmask
  uint32_t shader_core_bitmask;  // Shader core counter selection bitmask
  uint32_t tiler_bitmask;        // Tiler counter selection bitmask
  uint32_t mmu_l2_bitmask;       // MMU L2 counter selection bitmask
};

#define MALI_IOCTL_COUNTER_SETUP_READER \
  _IOW(MALI_IOCTL_TYPE, 8, struct mali_counter_reader_setup)

struct mali_counter_reader_metadata {
  uint64_t timestamp;
  uint32_t event_id;
  uint32_t buffer_index;
};

#define MALI_COUNTER_READER_IOCTL_TYPE 0xBE

#define MALI_COUNTER_READER_API_VERSION 1

#define MALI_COUNTER_READER_GET_HARDWARE_VERSION \
  _IOR(MALI_COUNTER_READER_IOCTL_TYPE, 0x00, uint32_t)
#define MALI_COUNTER_READER_GET_BUFFER_SIZE \
  _IOR(MALI_COUNTER_READER_IOCTL_TYPE, 0x01, uint32_t)
#define MALI_COUNTER_READER_DUMP \
  _IOW(MALI_COUNTER_READER_IOCTL_TYPE, 0x10, uint32_t)
#define MALI_COUNTER_READER_CLEAR \
  _IOW(MALI_COUNTER_READER_IOCTL_TYPE, 0x11, uint32_t)
#define MALI_COUNTER_READER_GET_BUFFER       \
  _IOR(MALI_COUNTER_READER_IOCTL_TYPE, 0x20, \
       struct mali_counter_reader_metadata)
#define MALI_COUNTER_READER_PUT_BUFFER       \
  _IOW(MALI_COUNTER_READER_IOCTL_TYPE, 0x21, \
       struct mali_counter_reader_metadata)
#define MALI_COUNTER_READER_GET_API_VERSION \
  _IOW(MALI_COUNTER_READER_IOCTL_TYPE, 0xFF, uint32_t)

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // THIRD_PARTY_LINUX_MALI_DRIVER_IOCTL_H_
