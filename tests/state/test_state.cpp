#include "gtest/gtest.h"
#include "state/state.hpp"

namespace pda {

class StateTest : public ::testing::Test {
protected:
  void SetUp() override {
    q1 = new State("q1");
    q2 = new State("q2");

    t = new Transition("a", "S", q1, "A Z", pda_tape, pda_stack);
  }

  void TearDown() override {
    delete q1;
    delete q2;
  }

  State *q1{nullptr};
  State *q2{nullptr};
  Transition *t{nullptr};

  Tape pda_tape;
  Stack pda_stack;
};

TEST_F(StateTest, Name) {
  ASSERT_EQ(q1->name(), "q1");
}

TEST_F(StateTest, EmptyNameInitialization) {
  ASSERT_THROW({ pda::State q(""); }, std::runtime_error);
}

TEST_F(StateTest, IsFinal) {
  q1->setFinal(true);

  ASSERT_TRUE(q1->isFinal());
  ASSERT_FALSE(q2->isFinal());
}

TEST_F(StateTest, AddTransition) {
  // Just check that anything breaks on adding a transition
  q1->addTransition(*t);
}

TEST_F(StateTest, HasTransition) {
  ASSERT_FALSE(q1->hasTransition("a", "S"));

  q1->addTransition(*t);

  ASSERT_TRUE(q1->hasTransition("a", "S"));
}

TEST_F(StateTest, GetTransition) {
  q1->addTransition(*t);
  auto returned_t = q1->transition("a", "S");

  ASSERT_EQ(returned_t, *t);
}

TEST_F(StateTest, GetInexistentTransition) {
  ASSERT_THROW({ q1->transition("foo", "bar"); }, std::runtime_error);;
}

}  // namespace pda
