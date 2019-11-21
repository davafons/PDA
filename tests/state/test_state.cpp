#include "gtest/gtest.h"
#include "state/state.hpp"

TEST(State, initialization) {
  pda::State q1("q1");

  ASSERT_EQ(q1.name(), "q1");
}
