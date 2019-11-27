#include "gtest/gtest.h"
#include "state/state.hpp"

namespace pda {

class StateTest : public ::testing::Test {
protected:
  void SetUp() override {
    s1_ = new State("s1");
    s2_ = new State("s2");
  }

  void TearDown() override {
    delete s1_;
    delete s2_;
  }

  State* s1_;
  State* s2_;
};

TEST_F(StateTest, Name) {
  ASSERT_EQ(s1_->name(), "s1");
}

TEST_F(StateTest, EmptyNameInit) {
  ASSERT_THROW({ State s(""); }, std::runtime_error);
}

TEST_F(StateTest, isFinal) {
  ASSERT_FALSE(s1_->isFinal());

  s1_->setFinal(true);

  ASSERT_TRUE(s1_->isFinal());
}

}  // namespace pda
