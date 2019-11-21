#include "pda.hpp"

#include "transition.hpp"

namespace pda {

Pda::Pda() {}

Pda::~Pda() {
  for (const auto& s : states_) {
    delete s.second;
  }
}

State* Pda::state(const std::string& name) const {
  return states_[name];
}

void Pda::addState(const std::string& name) {
  states_[name] = new State(name);
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
