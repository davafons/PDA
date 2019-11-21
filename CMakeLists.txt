cmake_minimum_required(VERSION 3.5.0)

project(pda)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

add_executable(${PROJECT_NAME})
add_subdirectory(src)


include(cmake/googletest.cmake)
fetch_googletest(
  ${PROJECT_SOURCE_DIR}/cmake
  ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()
add_subdirectory(tests)
