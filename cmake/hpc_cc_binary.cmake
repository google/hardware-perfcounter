include(CMakeParseArguments)

# Defines a C/C++ binary
#
# Given a binary 'foo' defined in root/a/b, this function will define a CMake
# target 'root_a_b_foo', which generates a binary of name 'foo'.
#
# Parameters:
#
# * NAME: the name of this binary
# * SRCS: the list of source files for this binary
# * DEPS: the list of libraries that this binary depends on
# * INCLUDES: the list of additional private include directories
# * COPTS: the list of private compile options
function(hpc_cc_binary)
  cmake_parse_arguments(
    _RULE
    ""
    "NAME"
    "SRCS;DEPS;INCLUDES,COPTS"
    ${ARGN}
  )

  hpc_package_ns("" "" _PACKAGE_NS)
  # Use fully qualified namespaces for dependencies
  list(TRANSFORM _RULE_DEPS REPLACE "^::" "${_PACKAGE_NS}::")

  # Prefix the library with the package name
  hpc_package_name("" "" _PACKAGE_NAME)
  set(_NAME "${_PACKAGE_NAME}-${_RULE_NAME}")

  add_executable(${_NAME} "")
  # Create an alias executable for the original given name
  add_executable(${_RULE_NAME} ALIAS "${_NAME}")
  # Use the original given name for the output binary
  set_target_properties(${_NAME} PROPERTIES OUTPUT_NAME "${_RULE_NAME}")

  target_sources(${_NAME} PRIVATE ${_RULE_SRCS})

  target_include_directories(${_NAME}
    PRIVATE
      "$<BUILD_INTERFACE:${HPC_SOURCE_ROOT}>/include"
      "$<BUILD_INTERFACE:${_RULE_INCLUDES}>"
  )

  target_compile_options(${_NAME} PRIVATE ${_RULE_COPTS})

  target_link_libraries(${_NAME} PRIVATE ${_RULE_DEPS})
endfunction()
