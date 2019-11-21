add_executable(
  pda_tests
  state/test_state.cpp
  state/test_tape.cpp
  state/test_pda.cpp
)

target_sources(
  pda_tests
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/state/state.cpp
  ${PROJECT_SOURCE_DIR}/src/state/transition.cpp
  ${PROJECT_SOURCE_DIR}/src/state/tape.cpp
  ${PROJECT_SOURCE_DIR}/src/state/pda.cpp
)

target_link_libraries(pda_tests gtest_main)
target_include_directories(pda_tests PRIVATE "${PROJECT_SOURCE_DIR}/src")

add_test(TARGET pda_tests)
