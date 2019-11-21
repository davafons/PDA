#pragma once

#include <functional>
#include <stack>
#include <string>

#include "tape.hpp"

namespace pda {

using Symbol = std::string;
using Stack = std::stack<Symbol>;

class State;

class Transition {
public:
  Transition(const Symbol& input_symbol,
             const Symbol& stack_symbol,
             const State* next_state,
             const Symbol& next_stack_symbols,
             Tape& tape,
             Stack& stack);

  Symbol inputSymbol() const;
  Symbol stackSymbol() const;

  const State* nextState();

private:
  Symbol input_symbol_;
  Symbol stack_symbol_;
  Symbol next_stack_symbol_;

  const State* next_state_;

  std::reference_wrapper<Tape> tape_;
  std::reference_wrapper<Stack> stack_;
};

}  // namespace pda
