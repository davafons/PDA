add_executable(
  pda_tests
  test_example.cpp
)

target_link_libraries(pda_tests gtest_main)

add_test(TARGET pda_tests)
