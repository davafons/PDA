#include "pda.hpp"

#include <iostream>

#include "transition.hpp"

namespace pda {

Pda::Pda() {}

Pda::~Pda() {
  for (const auto& s : states_) {
    delete s.second;
  }
}

State* Pda::startState() const {
  return start_state_;
}

void Pda::setStartState(const std::string& name) {
  if (name.empty()) {
    start_state_ = nullptr;
  } else {
    start_state_ = state(name);
  }
}

State* Pda::state(const std::string& name) const {
  try {
    return states_.at(name);
  } catch (std::out_of_range& e) {
    std::cerr << "> ERROR: State " << name << " is not defined." << std::endl;
  }
  return nullptr;
}

void Pda::addState(const std::string& name) {
  if (states_.count(name)) {
    std::cerr << "> WARNING: A state with name \"" << name
              << "\" already exists. The state WILL NOT be replaced." << std::endl;
  } else {
    states_[name] = new State(name);
  }
}

void Pda::addTransition(const std::string& sf,
                        const Symbol& input_symbol,
                        const Symbol& stack_symbol,
                        const std::string& st,
                        const Symbol& next_stack_symbol) {

  states_[sf]->addTransition(Transition(
      input_symbol, stack_symbol, states_[st], next_stack_symbol, input_tape_, stack_));
}

}  // namespace pda
