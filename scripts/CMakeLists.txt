find_package(Python3 QUIET COMPONENTS Interpreter)

if(Python3_Interpreter_FOUND)
  add_custom_command(
    OUTPUT
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a5xx.h"
      "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/a6xx.h"
    COMMAND
      "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/generate_adreno_definitions.py"
        --a5xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a5xx.xml"
        --a6xx_xml
          "${HPC_SOURCE_ROOT}/third_party/envytools/registers/adreno/a6xx.xml"
        --header_dir
          "${HPC_SOURCE_ROOT}/include/hpc/gpu/adreno/"
        --lib_dir
          "${HPC_SOURCE_ROOT}/lib/gpu/adreno/"
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
  )
endif(Python3_Interpreter_FOUND)
