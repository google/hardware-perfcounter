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

include(CMakeParseArguments)

# Defines a C/C++ library
#
# Given a library 'foo' defined in root/a/b, this function will define a CMake
# target 'root_a_b_foo' and its alias 'root::a::b::foo'.
#
# Parameters:
#
# * NAME: the name of this library
# * SRCS: the list of source files for this library
# * PUBLIC_HEADERS: the list of public headers for this library
# * PUBLIC_DEPS: the list of public libraries that this library depends on
# * PRIVATE_INCLUDES: the list of additional private include directories to this library
# * PRIVATE_COPTS: the list of private compile options
# * PRIVATE_DEPS: the list of private link options
# * INSTALL_COMPONENT: the installation component this target belongs to
function(hpc_cc_library)
  cmake_parse_arguments(
    _RULE
    ""
    "NAME;INSTALL_COMPONENT"
    "PUBLIC_HEADERS;SRCS;PUBLIC_DEPS;PRIVATE_INCLUDES;PRIVATE_COPTS;PRIVATE_DEPS"
    ${ARGN}
  )

  hpc_package_ns("lib" "hpc" _PACKAGE_NS)
  # Use fully qualified namespaces for dependencies
  list(TRANSFORM _RULE_PUBLIC_DEPS REPLACE "^::" "${_PACKAGE_NS}::")
  list(TRANSFORM _RULE_PRIVATE_DEPS REPLACE "^::" "${_PACKAGE_NS}::")

  # Prefix the library with the package name
  hpc_package_name("lib" "hpc" _PACKAGE_NAME)
  set(_NAME "${_PACKAGE_NAME}-${_RULE_NAME}")
  set(_ALIAS_NAME "${_PACKAGE_NS}::${_RULE_NAME}")

  add_library(${_NAME})
  # Create an alis library with the namespaced name for dependency reference use
  add_library(${_ALIAS_NAME} ALIAS ${_NAME})

  target_sources(${_NAME} PRIVATE ${_RULE_SRCS} ${_RULE_PUBLIC_HEADERS})

  target_include_directories(${_NAME}
    PUBLIC
      "$<BUILD_INTERFACE:${HPC_SOURCE_ROOT}>/include"
    PRIVATE
      "$<BUILD_INTERFACE:${_RULE_PRIVATE_INCLUDES}>"
  )

  target_compile_options(${_NAME} PRIVATE ${_RULE_PRIVATE_COPTS})

  target_link_libraries(${_NAME}
    PUBLIC ${_RULE_PUBLIC_DEPS}
    PRIVATE ${_RULE_PRIVATE_DEPS}
  )

  install(TARGETS ${_NAME}
    EXPORT hpc-lib-targets
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    COMPONENT ${_RULE_INSTALL_COMPONENT}
  )
endfunction()
