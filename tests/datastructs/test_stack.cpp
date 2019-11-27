#include "datastructs/stack.hpp"
#include "gtest/gtest.h"

namespace pda {

class StackTest : public ::testing::Test {
protected:
  void SetUp() override {
    stack_.alphabet().addSymbols("A B C");
    stack_.setStartSymbol("A");
  }

  Stack stack_;
};

TEST_F(StackTest, Empty) {
  ASSERT_FALSE(stack_.empty());
}

TEST_F(StackTest, Size) {
  ASSERT_EQ(stack_.size(), 1);
}

TEST_F(StackTest, Clear) {
  ASSERT_FALSE(stack_.empty());

  stack_.clear();

  ASSERT_TRUE(stack_.empty());
}

TEST_F(StackTest, Top) {
  ASSERT_EQ(stack_.top(), "A");
}

TEST_F(StackTest, Pop) {
  stack_.pop();

  ASSERT_EQ(stack_.size(), 0);
  ASSERT_TRUE(stack_.empty());
}

TEST_F(StackTest, SetStartSymbol) {
  ASSERT_EQ(stack_.size(), 1);
  ASSERT_EQ(stack_.top(), "A");

  stack_.setStartSymbol("S");

  ASSERT_EQ(stack_.size(), 1);
  ASSERT_EQ(stack_.top(), "S");
}

TEST_F(StackTest, pushSymbols) {
  stack_.clear();

  // Alphabet has symbols "A B C". "DE" will be skipped
  // Symbols are inserted right to left
  stack_.pushSymbols("ABCDE");

  ASSERT_EQ(stack_.size(), 3);
  ASSERT_EQ(stack_.top(), "A");
}

TEST_F(StackTest, pushLambda) {
  stack_.clear();
  ASSERT_TRUE(stack_.empty());

  stack_.pushSymbols(Utils::lambda);
  ASSERT_TRUE(stack_.empty());
}

}  // namespace pda
