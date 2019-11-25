cmake_minimum_required(VERSION 3.5.0)

project(pda)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

add_executable(${PROJECT_NAME})
add_subdirectory(src)

# Add required flags (GCC & LLVM/Clang)
target_compile_options(${PROJECT_NAME} PUBLIC
-O0        # no optimization
-g         # generate debug info
-fprofile-arcs
-ftest-coverage
--coverage # sets all required flags
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
  target_link_options(${PROJECT_NAME} PUBLIC --coverage)
else()
  target_link_libraries(${PROJECT_NAME} PUBLIC --coverage)
endif()

include(cmake/googletest.cmake)
fetch_googletest(
  ${PROJECT_SOURCE_DIR}/cmake
  ${PROJECT_BINARY_DIR}/googletest
)
#
# enable_testing()
# add_subdirectory(tests)
