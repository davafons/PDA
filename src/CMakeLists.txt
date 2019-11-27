# Compile sources as library
add_library(pdalib)

add_subdirectory(datastructs)
add_subdirectory(core)
add_subdirectory(state)
add_subdirectory(utils)

target_include_directories(
  pdalib
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pdalib coverage_config)

# Generate executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pdalib Boost::program_options)
