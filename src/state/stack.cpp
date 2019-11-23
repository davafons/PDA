#include "stack.hpp"

namespace pda {

Alphabet& Stack::alphabet() {
  return alphabet_;
}

const Alphabet& Stack::alphabet() const {
  return alphabet_;
}

void Stack::setStartSymbol(const Symbol& symbol) {
  clear();

  push(symbol);
}

void Stack::pushSymbols(const std::string& symbols_str) {
  for (const auto& symbol : alphabet_.split(symbols_str)) {
    if (symbol != Constant::lambda) {
      push(symbol);
    }
  }
}

void Stack::clear() {
  while (!empty()) {
    pop();
  }
}

std::ostream& operator<<(std::ostream& os, const Stack& s) {
  os << "Top: [" << ((s.empty()) ? "" : s.top()) << "]" << std::endl;

  return os;
}

}  // namespace pda
