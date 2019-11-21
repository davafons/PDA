#include "state.hpp"

namespace pda {

State::State(const std::string& name) : name_(name) {}

std::string State::name() const {
  return name_;
}

void State::setName(const std::string& name) {
  name_ = name;
}

void State::addTransition(const std::string& input_symbol,
                          const std::string& stack_symbol,
                          const Transition& transition) {}

}  // namespace pda
