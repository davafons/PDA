#pragma once

#include <map>
#include <string>

#include "state/transition.hpp"
#include "state/utils.hpp"

namespace pda {

class State {
public:
  explicit State(const std::string& name);
  std::string name() const;

  bool isFinal() const;
  void setFinal(bool f);

  std::vector<Transition>& transition(const Symbol& input_symbol,
                                      const Symbol& stack_symbol);
  void addTransition(const Transition& transition);

private:
  const std::string name_;

  bool final_{false};

  std::map<std::pair<Symbol, Symbol>, std::vector<Transition>> transitions_;
};

}  // namespace pda
