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

# Generate executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pdalib)
