find_package(Python3 QUIET COMPONENTS Interpreter)

if(Python3_Interpreter_FOUND)
  add_custom_command(
    OUTPUT
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/a5xx.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/a6xx.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/common.c"
    COMMAND
      "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/generate_adreno_definitions.py"
        --a5xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a5xx.xml"
        --a6xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a6xx.xml"
        -o
          "${HPC_SOURCE_ROOT}"
    DEPENDS
      "${CMAKE_CURRENT_SOURCE_DIR}/generate_adreno_definitions.py"
      "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a5xx.xml"
      "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a6xx.xml"
    COMMENT "Generating Adreno definitions"
  )

  add_custom_target(hpc-adreno-definitions
    DEPENDS
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/common.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/a5xx.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/a6xx.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/adreno/common.c"
  )

  add_custom_command(
    OUTPUT
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/valhall.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/bifrost.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/common.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/valhall.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/bifrost.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/context.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/context.c"
    COMMAND
      "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/generate_mali_definitions.py"
        --mali_xml
          "${HPC_SOURCE_ROOT}/third_party/hwcpipe/mali_gpu_database.xml"
        -o
          "${HPC_SOURCE_ROOT}"
    DEPENDS
      "${CMAKE_CURRENT_SOURCE_DIR}/generate_mali_definitions.py"
      "${HPC_SOURCE_ROOT}/third_party/hwcpipe/mali_gpu_database.xml"
    COMMENT "Generating Mali definitions"
  )

  add_custom_target(hpc-mali-definitions
    DEPENDS
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/common.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/valhall.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/mali/bifrost.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/common.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/valhall.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/bifrost.c"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/context.h"
      "${HPC_SOURCE_ROOT}/lib/gpu/mali/context.c"
  )
endif(Python3_Interpreter_FOUND)
