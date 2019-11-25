#pragma once

#include <vector>
#include <string>

#include "datastructs/alphabet.hpp"
#include "utils/utils.hpp"

namespace pda {

class Stack : private std::vector<Symbol> {
public:
  using std::vector<Symbol>::vector;

  bool empty() const noexcept;

  Symbol& top();
  const Symbol& top() const;

  void pop();

  void setStartSymbol(const Symbol& symbol);
  void pushSymbols(const std::string& symbols);

  Alphabet& alphabet();
  const Alphabet& alphabet() const;

  friend std::ostream& operator<<(std::ostream& os, const Stack& s);

private:
  Alphabet alphabet_;
};

}  // namespace pda
