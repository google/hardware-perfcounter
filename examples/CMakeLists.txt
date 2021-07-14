if(HPC_ENABLE_GPU_ADRENO)
  hpc_cc_binary(
    NAME
      adreno_common_c_example
    SRCS
      adreno_common_c_example.c
    DEPS
      hpc::gpu::adreno::common
  )

  hpc_cc_binary(
    NAME
      adreno_a6xx_c_example
    SRCS
      adreno_a6xx_c_example.c
    DEPS
      hpc::gpu::adreno::a6xx
  )
endif(HPC_ENABLE_GPU_ADRENO)

if(HPC_ENABLE_GPU_MALI)
  hpc_cc_binary(
    NAME
      mali_print_info
    SRCS
      mali_print_info.c
  )

  hpc_cc_binary(
    NAME
      mali_common_c_example
    SRCS
      mali_common_c_example.c
    DEPS
      hpc::gpu::mali::common
  )

  hpc_cc_binary(
    NAME
      mali_valhall_c_example
    SRCS
      mali_valhall_c_example.c
    DEPS
      hpc::gpu::mali::valhall
  )
endif(HPC_ENABLE_GPU_MALI)
