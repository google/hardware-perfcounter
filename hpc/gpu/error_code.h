#ifndef HPC_GPU_ERROR_CODE_H_
#define HPC_GPU_ERROR_CODE_H_

/// Error codes used by this library.
typedef enum hpc_gpu_error_e {
  /// The first error code used by this library.
  ///
  /// A large number is chosen here to make sure we don't overlap with error
  /// codes from the kernel.
  HPC_GPU_FIRST_ERROR_CODE = 1000,
  /// The current GPU device is unknown.
  HPC_GPU_ERROR_UNKNOWN_DEVICE = HPC_GPU_FIRST_ERROR_CODE,
  /// The current GPU device is incompatible.
  HPC_GPU_ERROR_INCOMPATIBLE_DEVICE,
} hpc_gpu_error_t;

#endif  // HPC_GPU_ERROR_CODE_H_
