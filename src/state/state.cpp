#include "state.hpp"

#include <iostream>

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

std::unordered_set<Transition>& State::transitions(const Symbol& input_symbol,
                                                   const Symbol& stack_symbol) {
  auto key = std::make_pair(input_symbol, stack_symbol);
  return transitions_[key];
}

void State::addTransition(const Transition& transition) {
  auto key = std::make_pair(transition.inputSymbol(), transition.stackSymbol());

  transitions_[key].insert(transition);
}

std::ostream& operator<<(std::ostream& os, const State& state) {
  for (const auto& t_pair : state.transitions_) {
    os << state.name() << ": [ ";
    for (const auto& t : t_pair.second) {
      os << t << ", ";
    }
    os << "\b\b ]" << std::endl;
  }
  return os;
}

}  // namespace pda
