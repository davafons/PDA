#include "transition.hpp"

#include "state/state.hpp"

namespace pda {

/*!
 *  \class Transition
 *  \brief Represents a transition to a new state.
 *
 *  Transition objects are inmutable.
 */

/*!
 *  Construct a new Transition object.
 */
Transition::Transition(const Symbol& input_symbol,
                       const Symbol& stack_symbol,
                       State* next_state,
                       const std::string& new_stack_symbols)

    : input_symbol_(input_symbol),
      stack_symbol_(stack_symbol),
      next_state_(next_state),
      new_stack_symbols_(new_stack_symbols) {

  // Remove spaces from the new_stack_symbols string
  new_stack_symbols_.erase(
      std::remove_if(new_stack_symbols_.begin(), new_stack_symbols_.end(), ::isspace),
      new_stack_symbols_.end());
}

/*!
 *  Symbol needed by the tape for the transition.
 */
Symbol Transition::inputSymbol() const {
  return input_symbol_;
}

/*!
 *  Symbol needed by the stack for the transition.
 */
Symbol Transition::stackSymbol() const {
  return stack_symbol_;
}

/*!
 *  Name of the next state to transition.
 */
std::string Transition::nextStateName() const {
  return (next_state_) ? next_state_->name() : "";
}

/*!
 *  New symbols to be pushed to the stack on the transition.
 */
std::string Transition::newStackSymbols() const {
  return new_stack_symbols_;
}

/*!
 *  Move to the next state and return it, modifying the tape and the stack on the
 *  process.
 */
State* Transition::nextState(Tape& current_tape, Stack& current_stack) const {
  if (current_stack.empty()) {
    throw std::runtime_error("> ERROR: Stack is empty.");
  }

  if (input_symbol_ != Utils::lambda && input_symbol_ != current_tape.peek()) {
    return nullptr;
  }

  if (stack_symbol_ != current_stack.top()) {
    return nullptr;
  }

  // Lambda transitions don't consume any symbol on the input tape.
  if (input_symbol_ != Utils::lambda) {
    current_tape.next();
  }

  current_stack.pop();

  current_stack.pushSymbols(new_stack_symbols_);

  return next_state_;
}

/*!
 *  Check if two transitions are equal.
 *  Note: For two transitions to be equal, they must have the same symbols, and point to
 *  the same "next_state_" objet.
 */
bool Transition::operator==(const Transition& other) const {
  return input_symbol_ == other.input_symbol_ && stack_symbol_ == other.stack_symbol_ &&
         new_stack_symbols_ == other.new_stack_symbols_ &&
         &next_state_ == &other.next_state_;
}

/*!
 *  Print the transition.
 */
std::ostream& operator<<(std::ostream& os, const Transition& t) {
  os << "(" << t.input_symbol_ << ", " << t.stack_symbol_ << ") => {"
     << t.next_state_->name() << ", " << t.new_stack_symbols_ << "}";

  return os;
}

}  // namespace pda
