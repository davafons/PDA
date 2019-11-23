#include "state.hpp"

namespace pda {

State::State(const std::string& name) : name_(name) {
  if (name_.empty()) {
    throw std::runtime_error("Can't create a state with empty name!");
  }
}

std::string State::name() const {
  return name_;
}

bool State::isFinal() const {
  return final_;
}

void State::setFinal(bool f) {
  final_ = f;
}

bool State::hasTransition(const Symbol& input_symbol, const Symbol& stack_symbol) {
  return transitions_.count(std::make_pair(input_symbol, stack_symbol));
}

Transition& State::transition(const Symbol& input_symbol, const Symbol& stack_symbol) {
  // TODO: Throw error if cant find transition
  try {
    return transitions_.at(std::make_pair(input_symbol, stack_symbol));

  } catch (const std::out_of_range&) {
    throw std::runtime_error("State \"" + name() +
                             "\" doesn't have a transition with (" + input_symbol +
                             ", " + stack_symbol + ")");
  }
}

void State::addTransition(const Transition& transition) {
  auto key = std::make_pair(transition.inputSymbol(), transition.stackSymbol());

  transitions_.emplace(key, transition);
}

}  // namespace pda
