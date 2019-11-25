target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(datastructs)
add_subdirectory(pda)
add_subdirectory(state)
add_subdirectory(utils)
