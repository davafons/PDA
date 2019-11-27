cmake_minimum_required(VERSION 3.5.0)

project(pda)

# CMake config
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


# Language settins
set(CMAKE_CXX_STANDARD 14)


# Executable
add_subdirectory(src)


# Testing
include(cmake/googletest.cmake)
fetch_googletest(
  ${PROJECT_SOURCE_DIR}/cmake
  ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()
add_subdirectory(tests)
