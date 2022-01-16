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
