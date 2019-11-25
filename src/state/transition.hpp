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
             const std::string& new_stack_symbols);

  Symbol inputSymbol() const;
  Symbol stackSymbol() const;
  std::string nextStateName() const;
  std::string newStackSymbols() const;

  State* nextState(Tape& current_tape, Stack& current_stack) const;

  bool operator==(const Transition& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Transition& t);

private:
  Symbol input_symbol_{""};
  Symbol stack_symbol_{""};
  std::string new_stack_symbols_{""};

  State* next_state_{nullptr};
};

}  // namespace pda

template <>
struct std::hash<pda::Transition> {
  size_t operator()(const pda::Transition& obj) const {
    return std::hash<std::string>()(obj.inputSymbol() + obj.stackSymbol() +
                                    obj.nextStateName() + obj.newStackSymbols());
  }
};
