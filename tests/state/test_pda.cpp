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

TEST(Pda, setStartState) {
  pda::Pda pda;

  pda.addState("q1");

  // Initially, the start state must be null
  ASSERT_EQ(pda.startState(), nullptr);

  pda.setStartState("q1");

  // Now, start state must be "q1"
  ASSERT_EQ(pda.startState(), pda.state("q1"));

  pda.setStartState("");

  // Start state must be null again
  ASSERT_EQ(pda.startState(), nullptr);
}
