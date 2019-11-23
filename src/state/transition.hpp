#pragma once

#include <functional>
#include <string>
#include <vector>

#include "stack.hpp"
#include "tape.hpp"
#include "utils.hpp"

namespace pda {

class State;

class Transition {
public:
  Transition(const Symbol& input_symbol,
             const Symbol& stack_symbol,
             State* next_state,
             const std::string& new_stack_symbols,
             Tape& tape,
             Stack& stack);

  Symbol inputSymbol() const;
  Symbol stackSymbol() const;

  State* nextState();

  bool operator==(const Transition& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Transition& t);

private:
  Symbol input_symbol_;
  Symbol stack_symbol_;
  std::string new_stack_symbols_;

  State* next_state_;

  std::reference_wrapper<Tape> tape_;
  std::reference_wrapper<Stack> stack_;
};

}  // namespace pda
