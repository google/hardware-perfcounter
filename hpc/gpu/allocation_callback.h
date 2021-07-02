#ifndef HPC_GPU_ALLOCATION_CALLBACK_H_
#define HPC_GPU_ALLOCATION_CALLBACK_H_

#include <stddef.h>

/// Pointer to host memory allocation function.
typedef void* (*hpc_gpu_host_alloc_function)(void* user_data, size_t size);
/// Pointer to host memory free function.
typedef void (*hpc_gpu_host_free_function)(void* user_data, void* memory);

/// Struct containing host memory allocation/free functions.
typedef struct hpc_gpu_host_allocation_callbacks_t {
  /// User data that will be passed to `alloc`/`free`.
  void* user_data;
  hpc_gpu_host_alloc_function alloc;
  hpc_gpu_host_free_function free;
} hpc_gpu_host_allocation_callbacks_t;

#endif  // HPC_GPU_ALLOCATION_CALLBACK_H_
