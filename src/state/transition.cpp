#include "transition.hpp"

#include "state/state.hpp"

namespace pda {

/*!
 *  \class Transition
 *  \brief Represents a transition to a new state
 */

Transition::Transition(const Symbol& input_symbol,
                       const Symbol& stack_symbol,
                       State* next_state,
                       const std::string& new_stack_symbols)

    : input_symbol_(input_symbol),
      stack_symbol_(stack_symbol),
      next_state_(next_state),
      new_stack_symbols_(new_stack_symbols) {

  new_stack_symbols_.erase(
      std::remove_if(new_stack_symbols_.begin(), new_stack_symbols_.end(), ::isspace),
      new_stack_symbols_.end());
}

Symbol Transition::inputSymbol() const {
  return input_symbol_;
}

Symbol Transition::stackSymbol() const {
  return stack_symbol_;
}

std::string Transition::nextStateName() const {
  return (next_state_) ? next_state_->name() : "";
}

std::string Transition::newStackSymbols() const {
  return new_stack_symbols_;
}

State* Transition::nextState(Tape& current_tape, Stack& current_stack) const {
  if (input_symbol_ != Utils::lambda && input_symbol_ != current_tape.peek()) {
    return nullptr;
  }

  if (stack_symbol_ != current_stack.top()) {
    return nullptr;
  }

  if (input_symbol_ != Utils::lambda) {
    current_tape.next();
  }

  if (current_stack.empty()) {
    throw std::runtime_error("> ERROR: Stack is empty.");
  }

  current_stack.pop();

  current_stack.pushSymbols(new_stack_symbols_);

  return next_state_;
}

bool Transition::operator==(const Transition& other) const {
  return input_symbol_ == other.input_symbol_ && stack_symbol_ == other.stack_symbol_ &&
         new_stack_symbols_ == other.new_stack_symbols_ &&
         next_state_ == other.next_state_;
}

std::ostream& operator<<(std::ostream& os, const Transition& t) {
  os << "(" << t.input_symbol_ << ", " << t.stack_symbol_ << ") => {"
     << t.next_state_->name() << ", " << t.new_stack_symbols_ << "}";

  return os;
}

}  // namespace pda
