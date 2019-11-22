#pragma once

#include <stack>

#include "alphabet.hpp"
#include "utils.hpp"

namespace pda {

class Stack : public std::stack<Symbol> {
public:
  using std::stack<Symbol>::stack;

  Alphabet& alphabet();
  const Alphabet& alphabet() const;

  void setStartSymbol(const Symbol& symbol);

  void pushSymbols(const std::string& symbols);

  void clear();

  friend std::ostream& operator<<(std::ostream& os, const Stack& s);

private:
  Alphabet alphabet_;
};

}  // namespace pda
