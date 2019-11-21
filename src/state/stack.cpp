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

void Stack::clear() {
  while (!empty()) {
    pop();
  }
}

}  // namespace pda
