#pragma once

#include <map>
#include <string>

#include "state/transition.hpp"

namespace pda {

class State {
public:
  explicit State(const std::string& name);

  std::string name() const;
  void setName(const std::string& name);

  const State* transition(const Symbol& input_symbol, const Symbol& stack_symbol);
  void addTransition(const Transition& transition);

private:
  std::string name_;

  std::map<std::pair<Symbol, Symbol>, Transition> transitions_;
};

}  // namespace pda
