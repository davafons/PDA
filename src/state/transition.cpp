#include "transition.hpp"

#include "state/state.hpp"

namespace pda {

Transition::Transition(const Symbol& input_symbol,
                       const Symbol& stack_symbol,
                       State* next_state,
                       const std::string& new_stack_symbols,
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

std::ostream& operator<<(std::ostream& os, const Transition& t) {
  os << "(" << t.input_symbol_ << ", " << t.stack_symbol_ << ") => {"
     << t.next_state_->name() << ", " << t.new_stack_symbols_ << "}" << std::endl;

  return os;

}  // namespace pda

State* Transition::nextState() {
  if (input_symbol_ != tape_.get().peek()) {
    return nullptr;
  }

  if (stack_symbol_ != stack_.get().top()) {
    return nullptr;
  }

  tape_.get().next();

  // TODO: Throw error
  if (!stack_.get().empty()) {
    stack_.get().pop();
  }

  stack_.get().pushSymbols(new_stack_symbols_);

  return next_state_;
}

}  // namespace pda
