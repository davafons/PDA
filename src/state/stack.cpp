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
  auto symbols = alphabet_.split(symbols_str);

  for (auto symbol_it = symbols.crbegin(); symbol_it != symbols.crend(); ++symbol_it) {
    if (*symbol_it != Constant::lambda) {
      push(*symbol_it);
    }
  }
}

void Stack::clear() {
  while (!empty()) {
    pop();
  }
}

std::ostream& operator<<(std::ostream& os, const Stack& s) {
  os << "Top: [" << ((s.empty()) ? "" : s.top()) << "]";

  return os;
}

}  // namespace pda
