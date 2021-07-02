include(CMakeParseArguments)

# Defines a C/C++ library
#
# Given a library 'foo' defined in root/a/b, this function will define a CMake
# target 'root_a_b_foo' and its alias 'root::a::b::foo'.
#
# Parameters:
#
# * NAME: the name of this library
# * HDRS: the list of public headers for this library
# * SRCS: the list of source files for this library
# * DEPS: the list of public libraries that this library depends on
# * INCLUDES: the list of additional private include directories to this library
# * COPTS: the list of private compile options
# * LINKOPTS: the list of private link options
function(hpc_cc_library)
  cmake_parse_arguments(
    _RULE
    ""
    "NAME"
    "HDRS;SRCS;DEPS;INCLUDES;COPTS;LINKOPTS"
    ${ARGN}
  )

  hpc_package_ns(_PACKAGE_NS)
  # Use fully qualified namespaces for dependencies
  list(TRANSFORM _RULE_DEPS REPLACE "^::" "${_PACKAGE_NS}::")
  list(TRANSFORM _RULE_LINKOPTS REPLACE "^::" "${_PACKAGE_NS}::")

  # Prefix the library with the package name
  hpc_package_name(_PACKAGE_NAME)
  set(_NAME "${_PACKAGE_NAME}_${_RULE_NAME}")

  add_library(${_NAME})
  # Create an alis library with the namespaced name for dependency reference use
  add_library(${_PACKAGE_NS}::${_RULE_NAME} ALIAS ${_NAME})

  target_sources(${_NAME} PRIVATE ${_RULE_SRCS} ${_RULE_HDRS})

  target_include_directories(${_NAME}
    PUBLIC
      "$<BUILD_INTERFACE:${HPC_SOURCE_ROOT}>"
    PRIVATE
      "$<BUILD_INTERFACE:${_RULE_INCLUDES}>"
  )

  target_compile_options(${_NAME} PRIVATE ${_RULE_COPTS})

  target_link_libraries(${_NAME}
    PUBLIC ${_RULE_DEPS}
    PRIVATE ${_RULE_LINKOPTS}
  )
endfunction()
