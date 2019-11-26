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
  void addSymbols(const std::string& symbols_str);

  std::vector<Symbol> splitInSymbols(const std::string& symbols_str);

  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

private:
  std::string regex_str_{"\\" + Utils::lambda};
  std::regex regex_;
};

}  // namespace pda
