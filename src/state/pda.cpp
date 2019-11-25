#include "pda.hpp"

#include <iostream>

#include "transition.hpp"

namespace pda {

Pda::Pda() {}

Pda::~Pda() {
  for (const auto& s : states_) {
    delete s.second;
  }
}

Alphabet& Pda::tapeAlphabet() {
  return input_tape_.alphabet();
}

const Alphabet& Pda::tapeAlphabet() const {
  return input_tape_.alphabet();
}

Alphabet& Pda::stackAlphabet() {
  return stack_.alphabet();
}

const Alphabet& Pda::stackAlphabet() const {
  return stack_.alphabet();
}

const State* Pda::startState() const {
  return start_state_;
}

void Pda::setStartState(const std::string& name) {
  if (name.empty()) {
    start_state_ = nullptr;
  } else {
    start_state_ = state(name);
  }
}

void Pda::setStackStartSymbol(const Symbol& symbol) {
  stack_.setStartSymbol(symbol);
}

void Pda::setFinalStates(const std::string& names) {
  for (const auto& name : splitSymbols(names)) {
    auto* s = state(name);
    if (s) {
      s->setFinal(true);
    }
  }
}

void Pda::setPdaType(Type type) {
  pda_type_ = type;
}

bool Pda::run(const std::string& input_str) {
  input_tape_.setInputString(input_str);

  State* current = start_state_;

  return run(current, input_tape_, stack_);

  // do {
  //   std::cout << input_tape_;
  //   std::cout << "Stack: " << stack_ << std::endl;
  //
  //   std::cout << "Current state: " << current->name() << std::endl;
  //
  //   Symbol input_symbol = input_tape_.peek();
  //   Symbol stack_symbol = stack_.top();
  //
  //   for (const auto& t : current->transition(input_symbol, stack_symbol)) {
  //     std::cout << "> Transition: " << t << std::endl;
  //
  //     current = t.nextState(input_tape_, stack_);
  //   }
  //
  // } while (input_tape_.hasNext());
  //
  // if (pda_type_ == Type::FinalState) {
  //   return (current && current->isFinal());
  // } else {
  //   return stack_.empty();
  // }
}

State* Pda::state(const std::string& name) const {
  try {
    return states_.at(name);

  } catch (std::out_of_range& e) {
    throw std::runtime_error("> ERROR: State" + name + " is not defined.");
  }
}

void Pda::addState(const std::string& name) {
  if (states_.count(name)) {
    std::cerr << "> WARNING: A state with name \"" << name
              << "\" already exists. The state WILL NOT be replaced." << std::endl;
  } else {
    states_[name] = new State(name);
  }
}

void Pda::addStates(const std::vector<std::string>& names) {
  for (const auto& name : names) {
    addState(name);
  }
}

void Pda::addStates(const std::string& names) {
  addStates(splitSymbols(names));
}

void Pda::addTransition(const std::string& from_str,
                        const Symbol& input_symbol,
                        const Symbol& stack_symbol,
                        const std::string& to_str,
                        const std::string& new_stack_symbols) {

  state(from_str)->addTransition(
      Transition(input_symbol, stack_symbol, state(to_str), new_stack_symbols));
}

bool Pda::run(State* current_state, Tape& current_tape, Stack& current_stack) {
  auto print_pda = [&current_state, &current_tape, &current_stack]() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Current state: " << current_state->name() << std::endl;
    std::cout << current_tape << std::endl;
    std::cout << "Stack: " << current_stack << std::endl;
    std::cout << "---------------------------" << std::endl;
  };

  print_pda();

  auto explore_transitions =
      [this, &print_pda, &current_state, &current_tape, &current_stack](
          const Symbol& input_symbol, const Symbol& stack_symbol) {
        for (const auto& transition :
             current_state->transition(input_symbol, stack_symbol)) {
          std::cout << "> Transition: " << transition << std::endl;

          Tape new_tape(current_tape);
          Stack new_stack(current_stack);
          State* new_state = transition.nextState(new_tape, new_stack);

          bool result = run(new_state, new_tape, new_stack);

          if (result) {
            return true;
          }

          std::cout << ">> Can't continue. Going back to previous state" << std::endl;
          print_pda();
        }
        return false;
      };

  if (current_tape.hasNext()) {
    if (explore_transitions(current_tape.peek(), current_stack.top())) {
      return true;
    }
  }

  if (explore_transitions(Constant::lambda, current_stack.top())) {
    return true;
  }

  if (!current_tape.hasNext()) {
    if (pda_type_ == Type::FinalState) {
      return (current_state && current_state->isFinal());
    } else {
      return current_stack.empty();
    }
  }

  return false;
}

}  // namespace pda
