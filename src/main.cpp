#include <functional>
#include <iostream>
#include <stack>
#include <string>

#include "state/pda.hpp"

int main() {
  pda::Pda pda;

  pda.addState("q1");
  pda.addState("q2");
  pda.addState("q1");

  pda.addTransition("q1", "a", "Z", "q2", {"A", "Z"});
  pda.addTransition("q2", "a", "Z", "q1", {"A", "Z"});

  //
  // pda::Tape input_tape("a b c");
  // std::stack<pda::Symbol> stack;
  // stack.push("G");
  //
  // auto *q1 = new pda::State("q1");
  // auto *q2 = new pda::State("q2");
  //
  // q1->addTransition(pda::Transition("a", "Z", q2, "AZ", input_tape, stack));
  // q1->addTransition(pda::Transition("a", "G", q1, "AZ", input_tape, stack));
  //
  // auto *n = q1->transition("a", "G");
  //
  // if (n) {
  //   std::cout << n->name() << std::endl;
  // }

  return 0;
}
