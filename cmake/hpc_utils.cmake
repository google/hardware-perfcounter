#===------------------------------------------------------------------------===#
# Packages and Paths
#===------------------------------------------------------------------------===#

# Sets ${PACKAGE_NS} to the package namespace relative to source root,
# with '::' as the separator between path segments.
function(hpc_package_ns PACKAGE_NS)
  string(REPLACE ${HPC_SOURCE_ROOT} "" _PACKAGE ${CMAKE_CURRENT_LIST_DIR})
  string(SUBSTRING ${_PACKAGE} 1 -1 _PACKAGE)
  string(REPLACE "/" "::" _PACKAGE_NS ${_PACKAGE})
  set(${PACKAGE_NS} ${_PACKAGE_NS} PARENT_SCOPE)
endfunction()

# Sets ${PACKAGE_NAME} to the package name relative to source root,
# with '_' as the separator between path segments.
function(hpc_package_name PACKAGE_NAME)
  hpc_package_ns(_PACKAGE_NS)
  string(REPLACE "::" "_" _PACKAGE_NAME ${_PACKAGE_NS})
  set(${PACKAGE_NAME} ${_PACKAGE_NAME} PARENT_SCOPE)
endfunction()

# Sets ${PACKAGE_PATH} to the package path relative to source root,
# with '/' as the separator between path segments.
function(hpc_package_path PACKAGE_PATH)
  hpc_package_ns(_PACKAGE_NS)
  string(REPLACE "::" "/" _PACKAGE_PATH ${_PACKAGE_NS})
  set(${PACKAGE_PATH} ${_PACKAGE_PATH} PARENT_SCOPE)
endfunction()
