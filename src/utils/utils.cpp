#include "utils.hpp"

namespace pda {

const std::string Utils::lambda = ".";

std::vector<std::string> Utils::split(const std::string& str) {
  std::vector<Symbol> result;

  std::stringstream symbols_stream(str);

  Symbol symbol;
  while (symbols_stream >> symbol) {
    result.push_back(symbol);
  }

  return result;
}

}  // namespace pda
