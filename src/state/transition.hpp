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
             const State* next_state,
             const std::vector<Symbol>& new_stack_symbols,
             Tape& tape,
             Stack& stack);

  Symbol inputSymbol() const;
  Symbol stackSymbol() const;

  const State* nextState();

private:
  Symbol input_symbol_;
  Symbol stack_symbol_;
  std::vector<Symbol> new_stack_symbols_;

  const State* next_state_;

  std::reference_wrapper<Tape> tape_;
  std::reference_wrapper<Stack> stack_;
};

}  // namespace pda
