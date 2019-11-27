add_executable(pda_tests)

add_subdirectory(datastructs)
add_subdirectory(core)
add_subdirectory(state)
add_subdirectory(utils)

target_link_libraries(pda_tests gtest_main pdalib)

add_test(TARGET pda_tests)
