#pragma once

#include <regex>
#include <string>
#include <vector>

#include "utils.hpp"

namespace pda {

class Alphabet {
public:
  Alphabet();

  void addSymbol(Symbol symbol);

  template <typename Iter>
  void addSymbols(Iter begin, Iter end);
  void addSymbols(const std::vector<Symbol>& symbols);

  std::vector<Symbol> split(const std::string& input_str);

private:
  std::string regex_str_{" "};
  std::regex regex_;
};

}  // namespace pda
