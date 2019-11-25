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

std::vector<Transition>& State::transition(const Symbol& input_symbol,
                                           const Symbol& stack_symbol) {
  // TODO: Throw error if cant find transition

  auto key = std::make_pair(input_symbol, stack_symbol);
  return transitions_[key];
}

void State::addTransition(const Transition& transition) {
  auto key = std::make_pair(transition.inputSymbol(), transition.stackSymbol());

  transitions_[key].push_back(transition);
}

}  // namespace pda
