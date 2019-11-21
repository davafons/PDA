#include "state.hpp"

namespace pda {

State::State(const std::string& name) : name_(name) {}

std::string State::name() const {
  return name_;
}

void State::setName(const std::string& name) {
  name_ = name;
}

const State* State::transition(const Symbol& input_symbol, const Symbol& stack_symbol) {
  return transitions_.at(std::make_pair(input_symbol, stack_symbol)).nextState();
}

void State::addTransition(const Transition& transition) {
  auto key = std::make_pair(transition.inputSymbol(), transition.stackSymbol());

  transitions_.emplace(key, transition);
}

}  // namespace pda
