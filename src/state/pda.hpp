#pragma once

#include <map>

#include "stack.hpp"
#include "state.hpp"
#include "tape.hpp"
#include "utils.hpp"

namespace pda {

class Pda {
public:
  enum class Type { EmptyStack = 1, FinalState = 2 };

  Pda();
  ~Pda();

  Alphabet& tapeAlphabet();
  const Alphabet& tapeAlphabet() const;

  Alphabet& stackAlphabet();
  const Alphabet& stackAlphabet() const;

  const State* startState() const;
  void setStartState(const std::string& name);

  void setStackStartSymbol(const Symbol& symbol);

  void setFinalStates(const std::string& names);

  void setPdaType(Type type);

  bool run(const std::string& input);

  State* state(const std::string& name) const;
  void addState(const std::string& s);

  void addStates(const std::vector<std::string>& names);
  void addStates(const std::string& names);

  void addTransition(const std::string& sf,
                     const Symbol& input_symbol,
                     const Symbol& stack_symbol,
                     const std::string& st,
                     const std::string& new_stack_symbols);

private:
  Type pda_type_{Type::EmptyStack};

  Tape input_tape_;
  Stack stack_;

  std::map<std::string, State*> states_;

  State* start_state_{nullptr};
};

}  // namespace pda
