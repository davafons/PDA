#include "stack.hpp"

namespace pda {
bool Stack::empty() const noexcept {
  return std::vector<Symbol>::empty();
}

Symbol& Stack::top() {
  return std::vector<Symbol>::back();
}

const Symbol& Stack::top() const {
  return std::vector<Symbol>::back();
}

void Stack::pop() {
  std::vector<Symbol>::pop_back();
}

void Stack::setStartSymbol(const Symbol& symbol) {
  clear();

  std::vector<Symbol>::push_back(symbol);
}

void Stack::pushSymbols(const std::string& symbols_str) {
  auto symbols = alphabet_.splitInSymbols(symbols_str);

  for (auto symbol_it = symbols.crbegin(); symbol_it != symbols.crend(); ++symbol_it) {
    if (*symbol_it != Utils::lambda) {
      std::vector<Symbol>::push_back(*symbol_it);
    }
  }
}

Alphabet& Stack::alphabet() {
  return alphabet_;
}

const Alphabet& Stack::alphabet() const {
  return alphabet_;
}

std::ostream& operator<<(std::ostream& os, const Stack& st) {
  os << "[ ";

  for (auto it = st.crbegin(); it != st.crend(); ++it) {
    os << *it << " ";
  }

  os << "]\n";

  return os;
}

}  // namespace pda
