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

  State* transition(const std::string& input_symbol, const std::string& stack_symbol);

  void addTransition(const std::string& input_symbol,
                     const std::string& stack_symbol,
                     const Transition& transition);

private:
  std::string name_;

  std::map<std::string, Transition> transitions_;
};

}  // namespace pda
