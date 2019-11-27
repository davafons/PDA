#include "datastructs/tape.hpp"
#include "gtest/gtest.h"

namespace pda {

class TapeTest : public ::testing::Test {
protected:
  void SetUp() override {
    tape_.alphabet().addSymbols("A B C");
    tape_.setInputString("A");
  }

  Tape tape_;
};

TEST_F(TapeTest, InputStringConstructor) {
  tape_ = Tape("a b c");

  // Elements on the input string are inserted to the alphabet
  ASSERT_EQ(tape_.alphabet().size(), 3);
  ASSERT_EQ(tape_.size(), 3);
}

TEST_F(TapeTest, AlphabetConstructor) {
  tape_ = Tape("a b c", "a b");

  // Elements on the input string are inserted according to the alphabet (second string)
  ASSERT_EQ(tape_.alphabet().size(), 2);
  ASSERT_EQ(tape_.size(), 2);
}

TEST_F(TapeTest, Size) {
  ASSERT_EQ(tape_.size(), 1);
}

TEST_F(TapeTest, Peek) {
  ASSERT_EQ(tape_.peek(), "A");
}

TEST_F(TapeTest, CanReadNext) {
  ASSERT_TRUE(tape_.canRead());

  tape_.next();

  ASSERT_FALSE(tape_.canRead());
}

TEST_F(TapeTest, Reset) {
  ASSERT_TRUE(tape_.canRead());

  tape_.reset();

  ASSERT_FALSE(tape_.canRead());
}

TEST_F(TapeTest, InputString) {
  // Tape alphabet is "A B C"
  tape_.setInputString("ABCDE");

  ASSERT_EQ(tape_.size(), 3);
}

}  // namespace pda
