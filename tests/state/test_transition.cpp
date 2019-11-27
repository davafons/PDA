#include "gtest/gtest.h"
#include "state/transition.hpp"

namespace pda {
class TransitionTest : public ::testing::Test {
protected:
  Transition transition{"a", "S", nullptr, "A Z"};
};

TEST_F(TransitionTest, InputSymbol) {
  ASSERT_EQ(transition.inputSymbol(), "a");

}

}  // namespace pda
