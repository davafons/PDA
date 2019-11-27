add_executable(pda_tests)

add_subdirectory(datastructs)
add_subdirectory(core)
add_subdirectory(state)
add_subdirectory(utils)

target_link_libraries(pda_tests gtest_main pdalib)

add_test(TARGET ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pda_tests)

# Coverage
option(COVERALLS "Generate coverage data" OFF)
if(COVERALLS)
  include(Coveralls)

  coveralls_turn_on_coverage()

  target_link_libraries(pda_tests "-lgcov")

  get_target_property(SRC_FILES pdalib SOURCES)
  coveralls_setup("src/state/state.cpp" ON)
endif()
