# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
