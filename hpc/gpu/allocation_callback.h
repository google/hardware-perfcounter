#ifndef HPC_GPU_ALLOCATION_CALLBACK_H_
#define HPC_GPU_ALLOCATION_CALLBACK_H_

#include <stddef.h>

typedef void* (*hpc_gpu_host_alloc_function)(void* user_data, size_t size);
typedef void (*hpc_gpu_host_free_function)(void* user_data, void* memory);

typedef struct hpc_gpu_allocation_callbacks_t {
  void* user_data;
  hpc_gpu_host_alloc_function alloc;
  hpc_gpu_host_free_function free;
} hpc_gpu_allocation_callbacks_t;

#endif  // HPC_GPU_ALLOCATION_CALLBACK_H_
