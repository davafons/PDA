#pragma once

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

  const State* nextState();

private:
  const Symbol& input_symbol_;
  const Symbol& stack_symbol_;
  const State* next_state_;
  const Symbol& next_stack_symbol_;

  Tape& tape_;
  Stack& stack_;
};

}  // namespace pda
