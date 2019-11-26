#pragma once

#include <map>

#include "datastructs/stack.hpp"
#include "datastructs/tape.hpp"
#include "state/state.hpp"
#include "utils/utils.hpp"

namespace pda {

class Pda {
public:
  enum class Type { EmptyStack = 1, FinalState = 2 };

  ~Pda();

  // Alphabet
  Alphabet& tapeAlphabet();
  const Alphabet& tapeAlphabet() const;

  Alphabet& stackAlphabet();
  const Alphabet& stackAlphabet() const;

  // Stack
  void setStackStartSymbol(const Symbol& symbol);

  // States
  const State* startState() const;
  void setStartState(const std::string& name);
  void setFinalStates(const std::string& names_str);

  bool hasState(const std::string& name);
  State* state(const std::string& name) const;

  void addState(const std::string& s);
  void addStates(const std::string& names_str);

  // Transitions
  void addTransition(const std::string& transition_str);
  void addTransition(const std::string& sf,
                     const Symbol& input_symbol,
                     const Symbol& stack_symbol,
                     const std::string& st,
                     const std::string& new_stack_symbols);

  // Pda
  void setPdaType(Type type);
  bool run(const std::string& input);

  friend std::ostream& operator<<(std::ostream& os, const Pda& pda);

private:
  bool run(State* current_state, Tape& current_tape, Stack& current_stack);

private:
  Type type_{Type::EmptyStack};

  Tape input_tape_;
  Stack stack_;

  std::map<std::string, State*> states_;

  State* start_state_{nullptr};
};

}  // namespace pda
