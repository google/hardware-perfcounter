#ifndef HPC_GPU_ERROR_CODE_H_
#define HPC_GPU_ERROR_CODE_H_

typedef enum hpc_gpu_error_e {
  HPC_GPU_FIRST_ERROR_CODE = 1000,
  HPC_GPU_ERROR_UNKNOWN_DEVICE = HPC_GPU_FIRST_ERROR_CODE,
} hpc_gpu_error_t;

#endif  // HPC_GPU_ERROR_CODE_H_
