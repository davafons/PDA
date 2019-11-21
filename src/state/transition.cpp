#include "transition.hpp"

#include "state/state.hpp"

namespace pda {

Transition::Transition(const Symbol& input_symbol,
                       const Symbol& stack_symbol,
                       const State* next_state,
                       const Symbol& next_stack_symbol,
                       Tape& tape,
                       Stack& stack)

    : input_symbol_(input_symbol),
      stack_symbol_(stack_symbol),
      next_state_(next_state),
      next_stack_symbol_(next_stack_symbol),
      tape_(tape),
      stack_(stack) {}

const State* Transition::nextState() {
  if (input_symbol_ != tape_.peek()) {
    return nullptr;
  }

  if (stack_symbol_ != stack_.top()) {
    return nullptr;
  }

  tape_.next();
  stack_.pop();
  stack_.push(next_stack_symbol_);

  return next_state_;
}

}  // namespace pda
