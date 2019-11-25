#pragma once

#include <regex>
#include <string>
#include <vector>

#include "utils/utils.hpp"

namespace pda {

class Alphabet {
public:
  Alphabet() = default;

  bool empty() const;

  void reset();

  void addSymbol(Symbol symbol);

  void setSymbols(const std::vector<Symbol>& symbols);
  void setSymbols(const std::string& symbols_str);

  std::vector<Symbol> splitInSymbols(const std::string& symbols_str);

private:
  std::string regex_str_{"\\" + Utils::lambda};
  std::regex regex_;
};

}  // namespace pda
