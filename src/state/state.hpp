#pragma once

#include <map>
#include <string>
#include <unordered_set>

#include "state/transition.hpp"
#include "utils/utils.hpp"

namespace pda {

class Pda;

class State {
public:
  explicit State(const std::string& name);

  std::string name() const;

  bool isFinal() const;
  void setFinal(bool f);

  std::unordered_set<Transition>& transitions(const Symbol& input_symbol,
                                              const Symbol& stack_symbol);
  void addTransition(const Transition& transition);

  friend std::ostream& operator<<(std::ostream& os, const State& state);

private:
  const std::string name_;
  bool final_{false};

  std::map<std::pair<Symbol, Symbol>, std::unordered_set<Transition>> transitions_;
};

}  // namespace pda
