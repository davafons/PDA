#include "state.hpp"

State::State(const std::string& name) : name_(name) {}

std::string State::name() const {
  return name_;
}

void State::setName(const std::string& name) {
  name_ = name;
}
