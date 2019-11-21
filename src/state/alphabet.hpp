#pragma once

#include <regex>
#include <string>
#include <vector>

#include "utils.hpp"

namespace pda {

class Alphabet {
public:
  Alphabet();

  void reset();

  void addSymbol(Symbol symbol);

  void setSymbols(const std::vector<Symbol>& symbols);
  void setSymbols(const std::string& symbols_str);

  std::vector<Symbol> split(const std::string& input_str);

private:
  std::string regex_str_{"\\."};
  std::regex regex_;
};

}  // namespace pda
