#include "pda.hpp"

#include <iostream>
#include <sstream>

#include "state/transition.hpp"

namespace pda {
/*!
 *  \class Pda
 *  \brief Pushdown Automata (Pda) implementation
 */

/*!
 *  Delete all the states hold by the Pda.
 *  WARNING: After the Pda is destroyed, all Transitions pointing to a State of this Pda
 *  will point to an undefined State.
 */
Pda::~Pda() {
  for (const auto& s : states_) {
    delete s.second;
  }
}

/*!
 *  Return the Tape alphabet.
 */
Alphabet& Pda::tapeAlphabet() {
  return input_tape_.alphabet();
}

/*!
 *  Return the Tape alphabet.
 */
const Alphabet& Pda::tapeAlphabet() const {
  return input_tape_.alphabet();
}

/*!
 *  Return the Stack alphabet.
 */
Alphabet& Pda::stackAlphabet() {
  return stack_.alphabet();
}

/*!
 *  Return the Stack alphabet.
 */
const Alphabet& Pda::stackAlphabet() const {
  return stack_.alphabet();
}

/*!
 *  Set the initial symbol of the stack.
 */
void Pda::setStackStartSymbol(const Symbol& symbol) {
  stack_.setStartSymbol(symbol);
}

/*!
 *  Return the start (initial) state.
 */
const State* Pda::startState() const {
  return start_state_;
}

/*!
 *  Set a new start state. If "name" is an empty string, the start state will be set to
 *  none.
 */
void Pda::setStartState(const std::string& name) {
  if (name.empty()) {
    start_state_ = nullptr;
  } else {
    start_state_ = state(name);
  }
}

/*!
 *  Set which states are final.
 */
void Pda::setFinalStates(const std::string& names_str) {
  // First, reset all states to non-final.
  for (const auto& state : states_) {
    state.second->setFinal(false);
  }

  for (const auto& name : Utils::split(names_str)) {
    state(name)->setFinal(true);
  }
}

/*!
 *  Check if the Pda has a State with name "name".
 */
bool Pda::hasState(const std::string& name) {
  return states_.count(name);
}

/*!
 *  Return the state named "name".
 *  WARNING: If no state with name "name" is found, an exception is thrown. To avoid the
 *  exception, check if the state exists first with the "hasState" method.
 */
State* Pda::state(const std::string& name) const {
  try {
    return states_.at(name);

  } catch (std::out_of_range& e) {
    throw std::runtime_error("> ERROR: State " + name + " is not defined.");
  }
}

/*!
 *  Add a new state to the Pda.
 *  WARNING: If a state with the same name already exists, the new state will be ignored
 *  and not added.
 */
void Pda::addState(const std::string& name) {
  if (states_.count(name)) {
    std::cerr << "> WARNING: A state with name \"" << name
              << "\" already exists. The state WILL NOT be replaced." << std::endl;
  } else {
    states_[name] = new State(name);
  }
}

/*!
 *  For each state on "names_str", add it to the Pda.
 *  State names must be splitted by whitespaces.
 */
void Pda::addStates(const std::string& names_str) {
  for (const auto& name : Utils::split(names_str)) {
    addState(name);
  }
}

/*!
 *  Read a new transition to the State pointed by "from_str".
 *  Format: "from_state input_symbol stack_symbol to_state symbol_A symbol_B..."
 */
void Pda::addTransition(const std::string& transition_str) {
  std::stringstream transition_stream(transition_str);

  std::string from_str;
  Symbol input_symbol, stack_symbol;
  std::string to_str;

  transition_stream >> from_str >> input_symbol >> stack_symbol >> to_str;

  std::string new_stack_symbols;
  std::getline(transition_stream, new_stack_symbols);

  addTransition(from_str, input_symbol, stack_symbol, to_str, new_stack_symbols);
}

/*!
 *  Add a new transition to the State pointed by "from_str".
 */
void Pda::addTransition(const std::string& from_str,
                        const Symbol& input_symbol,
                        const Symbol& stack_symbol,
                        const std::string& to_str,
                        const std::string& new_stack_symbols) {

  state(from_str)->addTransition(
      Transition(input_symbol, stack_symbol, state(to_str), new_stack_symbols));
}

/*!
 *  Set the Type of Pda. This will be used to decide the Pda acceptance criteria.
 */
void Pda::setPdaType(Type type) {
  type_ = type;
}

/*!
 *  Execute the Pda for a new input string.
 */
bool Pda::run(const std::string& input_str) {
  input_tape_.setInputString(input_str);

  State* current = start_state_;

  return run(current, input_tape_, stack_);
}

/*!
 *  Run the Pda execution from the state, tape and stack provided.
 *
 *  Returns if the state ends on an acceptance state.
 */
bool Pda::run(State* current_state, Tape& current_tape, Stack& current_stack) {
  // Helper function to print the state of the Pda
  auto print_pda = [&current_state, &current_tape, &current_stack]() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Current state: " << current_state->name() << std::endl;
    std::cout << current_tape << std::endl;
    std::cout << "Stack: " << current_stack << std::endl;
    std::cout << "---------------------------" << std::endl;
  };

  print_pda();

  // Helper function to explore the transitions from the provided stack, and for the
  // provided symbols.
  // Returns if any of the transitions ended on an acceptance state.
  auto explore_transitions =
      [this, &print_pda, &current_state, &current_tape, &current_stack](
          const Symbol& input_symbol, const Symbol& stack_symbol) {
        for (const auto& transition :
             current_state->transitions(input_symbol, stack_symbol)) {
          std::cout << "> Transition: " << transition << std::endl;

          // For each transition, clone the tape and stack and call this method
          // recursively.
          Tape new_tape(current_tape);
          Stack new_stack(current_stack);
          State* new_state = transition.nextState(new_tape, new_stack);

          bool result = run(new_state, new_tape, new_stack);

          if (result) {
            return true;
          }

          std::cout << ">> Can't continue. Going back to previous state." << std::endl;
          print_pda();
        }

        return false;
      };

  // Has symbols on tape and stack, can keep transitioning.
  if (current_tape.canRead() && !current_stack.empty()) {
    if (explore_transitions(current_tape.peek(), current_stack.top())) {
      return true;
    }
  }

  // Try to use lambda transitions.
  if (!current_stack.empty()) {
    if (explore_transitions(Utils::lambda, current_stack.top())) {
      return true;
    }
  }

  // After reading the whole tape, check if the current state is an acceptance state.
  if (!current_tape.canRead()) {
    if (type_ == Type::FinalState) {
      return (current_state && current_state->isFinal());
    } else {
      return current_stack.empty();
    }
  }

  return false;
}

/*!
 *  Print the Pda information.
 */
std::ostream& operator<<(std::ostream& os, const Pda& pda) {
  os << "> PDA Type: "
     << ((pda.type_ == Pda::Type::EmptyStack) ? "Empty Stack" : "Final States")
     << std::endl;
  os << "> States: ";

  for (const auto& s : pda.states_) {
    os << s.second->name() << ((s.second->isFinal()) ? "*" : "") << " ";
  }

  os << std::endl;

  os << "> Input alphabet: " << pda.input_tape_.alphabet() << std::endl;
  os << "> Stack alphabet: " << pda.stack_.alphabet() << std::endl;
  os << "> Stack initial symbol: " << pda.stack_ << std::endl;

  os << "> Initial state: " << pda.start_state_->name() << std::endl;

  os << "> Transitions: " << std::endl;
  for (const auto& s_pair : pda.states_) {
    std::cout << *s_pair.second << std::endl;
  }

  return os;
}

}  // namespace pda
