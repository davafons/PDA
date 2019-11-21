#include "gtest/gtest.h"
#include "state/tape.hpp"

TEST(Tape, empty_initialization) {
  pda::Tape tape;

  ASSERT_FALSE(tape.hasNext());
}

TEST(Tape, initialization) {
  pda::Tape tape("a b c");

  ASSERT_EQ(tape.size(), 3);

  ASSERT_TRUE(tape.hasNext());
}

TEST(Tape, read_symbols) {
  pda::Tape tape("a b c");

  ASSERT_EQ(tape.peek(), "a");

  tape.next();
  ASSERT_EQ(tape.peek(), "b");

  tape.next();
  ASSERT_EQ(tape.peek(), "c");

  ASSERT_FALSE(tape.hasNext());
}
