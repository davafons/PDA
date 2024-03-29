#include "state.hpp"

#include <iostream>

namespace pda {

/*!
 *  \class State
 *  \brief Class representing a PDA State with transitions.
 *
 */

/*!
 *  Construct a new state object. MUST have a name.
 */
State::State(const std::string& name) : name_(name) {
  if (name_.empty()) {
    throw std::runtime_error("Can't create a state with empty name!");
  }
}

/*!
 *  Return the State name.
 */
std::string State::name() const {
  return name_;
}

/*!
 *  Return if the state is final.
 */
bool State::isFinal() const {
  return final_;
}

/*!
 *  Set if the state is final.
 */
void State::setFinal(bool f) {
  final_ = f;
}

/*!
 *  Return all the transitions associated to these input and stack symbols.
 *  If there aren't any transitions for the symbols, return an empty set.
 */
std::unordered_set<Transition>& State::transitions(const Symbol& input_symbol,
                                                   const Symbol& stack_symbol) {
  auto key = std::make_pair(input_symbol, stack_symbol);
  return transitions_[key];
}

/*!
 *  Add a new transition to the State.
 *  Note: All transitions are guaranteed to be unique. Can't add two equal transitions.
 */
void State::addTransition(const Transition& transition) {
  auto key = std::make_pair(transition.inputSymbol(), transition.stackSymbol());

  transitions_[key].insert(transition);
}

/*!
 *  Print the State name and its transitions.
 */
std::ostream& operator<<(std::ostream& os, const State& state) {
  for (const auto& t_pair : state.transitions_) {
    os << state.name() << ": [ ";
    for (const auto& t : t_pair.second) {
      os << t << ", ";
    }
    os << "\b\b ]" << std::endl;
  }
  return os;
}

}  // namespace pda
