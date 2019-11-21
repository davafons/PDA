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

  State* state(const std::string& name) const;
  void addState(const std::string& s);

  void addTransition(const std::string& sf,
                     const Symbol& input_symbol,
                     const Symbol& stack_symbol,
                     const std::string& st,
                     const Symbol& next_stack_symbol);

private:
  Tape input_tape_;
  Stack stack_;

  std::map<std::string, State*> states_;
};

}  // namespace pda