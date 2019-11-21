#pragma once

#include <map>

#include "state.hpp"
#include "tape.hpp"
#include "utils.hpp"

namespace pda {

class Pda {
public:
  Pda();
  ~Pda();

  State* startState() const;
  void setStartState(const std::string& name);

  State* state(const std::string& name) const;
  void addState(const std::string& s);

  void addTransition(const std::string& sf,
                     const Symbol& input_symbol,
                     const Symbol& stack_symbol,
                     const std::string& st,
                     const std::vector<Symbol>& new_stack_symbols);

private:
  Tape input_tape_;
  Stack stack_;

  std::map<std::string, State*> states_;

  State* start_state_{nullptr};
};

}  // namespace pda
