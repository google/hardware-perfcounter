find_package(Python3 QUIET COMPONENTS Interpreter)

if(Python3_Interpreter_FOUND)
  add_custom_command(
    OUTPUT
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.c"
    COMMAND
      "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/generate_adreno_definitions.py"
        --a5xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a5xx.xml"
        --a6xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a6xx.xml"
        -o
          "${HPC_SOURCE_ROOT}/hpc/gpu/adreno/"
    DEPENDS
      "${CMAKE_CURRENT_SOURCE_DIR}/generate_adreno_definitions.py"
      "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a5xx.xml"
      "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a6xx.xml"
    COMMENT "Generating Adreno definitions"
  )

  add_custom_target(hpc-adreno-definitions
    DEPENDS
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.c"
  )

  add_custom_command(
    OUTPUT
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/context.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/context.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.c"
    COMMAND
      "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/generate_mali_definitions.py"
        --mali_xml
          "${CMAKE_CURRENT_SOURCE_DIR}/mali_gpu_database.xml"
        -o
          "${HPC_SOURCE_ROOT}/hpc/gpu/mali/"
    DEPENDS
      "${CMAKE_CURRENT_SOURCE_DIR}/generate_mali_definitions.py"
      "${CMAKE_CURRENT_SOURCE_DIR}/mali_gpu_database.xml"
    COMMENT "Generating Mali definitions"
  )

  add_custom_target(hpc-mali-definitions
    DEPENDS
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/context.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/context.c"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.c"
  )
endif(Python3_Interpreter_FOUND)
