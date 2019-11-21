#include <stack>
#include <string>

#include "state/state.hpp"
#include "state/tape.hpp"
#include "state/transition.hpp"
#include "state/utils.hpp"

int main() {
  pda::Tape input_tape("a b c");

  std::stack<std::string> stack;

  auto *q1 = new pda::State("q1");
  auto *q2 = new pda::State("q2");

  // q1->addTransition(pda::Transition("a", "Z", "q2, "AZ", input_string, stack));
  //
  // auto * next_state = q1->transition("a", "Z");

  return 0;
}
