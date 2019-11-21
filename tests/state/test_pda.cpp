#include "gtest/gtest.h"
#include "state/pda.hpp"

TEST(Pda, initialization) {
  pda::Pda pda;
}

TEST(Pda, addState) {
  pda::Pda pda;

  pda.addState("q1");

  // Check existent and inesistent state
  ASSERT_NE(pda.state("q1"), nullptr);
  ASSERT_EQ(pda.state("q5"), nullptr);
}

TEST(Pda, addState_dont_replace) {
  pda::Pda pda;

  pda.addState("q1");

  auto *q1 = pda.state("q1");

  pda.addState("q1");

  ASSERT_EQ(q1, pda.state("q1"));
}
