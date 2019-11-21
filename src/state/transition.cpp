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

Symbol Transition::inputSymbol() const {
  return input_symbol_;
}

Symbol Transition::stackSymbol() const {
  return stack_symbol_;
}

const State* Transition::nextState() {
  if (input_symbol_ != tape_.get().peek()) {
    return nullptr;
  }

  if (stack_symbol_ != stack_.get().top()) {
    return nullptr;
  }

  tape_.get().next();
  stack_.get().pop();
  stack_.get().push(next_stack_symbol_);

  return next_state_;
}

}  // namespace pda
