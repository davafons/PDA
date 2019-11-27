add_executable(pda_tests)

add_subdirectory(datastructs)
add_subdirectory(core)
add_subdirectory(state)
add_subdirectory(utils)

target_link_libraries(pda_tests pdalib coverage_config gtest_main)

add_test(TARGET ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pda_tests)
