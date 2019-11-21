#include "utils.hpp"

namespace pda {

std::vector<Symbol> splitSymbols(const std::string& symbols_str) {
  std::vector<Symbol> result;

  std::stringstream symbols_stream(symbols_str);

  Symbol symbol;
  while (symbols_stream >> symbol) {
    result.push_back(symbol);
  }

  return result;
}

}  // namespace pda
