#include "transition.hpp"

#include "state/state.hpp"

namespace pda {

Transition::Transition(const Symbol& input_symbol,
                       const Symbol& stack_symbol,
                       const State* next_state,
                       const std::vector<Symbol>& new_stack_symbols,
                       Tape& tape,
                       Stack& stack)

    : input_symbol_(input_symbol),
      stack_symbol_(stack_symbol),
      next_state_(next_state),
      new_stack_symbols_(new_stack_symbols),
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

  for (const auto& symbol : new_stack_symbols_) {
    stack_.get().push(symbol);
  }

  return next_state_;
}

}  // namespace pda
