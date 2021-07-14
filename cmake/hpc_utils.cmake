#===------------------------------------------------------------------------===#
# Packages and Paths
#===------------------------------------------------------------------------===#

# Sets ${PACKAGE_NS} to the package namespace relative to source root, with '::'
# as the separator between path segments, and leading ${RM_PATH_PREFIX} replaced
# by ${ADD_PATH_PREFIX}.
function(hpc_package_ns RM_PATH_PREFIX ADD_PATH_PREFIX PACKAGE_NS)
  string(REPLACE "${HPC_SOURCE_ROOT}/" "" _PACKAGE "${CMAKE_CURRENT_LIST_DIR}")
  string(REPLACE "${RM_PATH_PREFIX}" "${ADD_PATH_PREFIX}" _PACKAGE "${_PACKAGE}")
  string(REPLACE "/" "::" _PACKAGE_NS "${_PACKAGE}")
  set(${PACKAGE_NS} "${_PACKAGE_NS}" PARENT_SCOPE)
endfunction()

# Sets ${PACKAGE_NAME} to the package name relative to source root, with '-'
# as the separator between path segments, and leading ${RM_PATH_PREFIX} replaced
# by ${ADD_PATH_PREFIX}.
function(hpc_package_name RM_PATH_PREFIX ADD_PATH_PREFIX PACKAGE_NAME)
  hpc_package_ns("${RM_PATH_PREFIX}" "${ADD_PATH_PREFIX}" _PACKAGE_NS)
  string(REPLACE "::" "-" _PACKAGE_NAME "${_PACKAGE_NS}")
  set(${PACKAGE_NAME} "${_PACKAGE_NAME}" PARENT_SCOPE)
endfunction()
