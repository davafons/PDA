#include "utils.hpp"

#include <algorithm>

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

std::string& Utils::trim(std::string& str) {
  return ltrim(rtrim(str));
}
std::string& Utils::ltrim(std::string& str) {
  auto it = std::find_if_not(str.begin(), str.end(), ::isspace);
  str.erase(str.begin(), it);
  return str;
}
std::string& Utils::rtrim(std::string& str) {
  auto it = std::find_if_not(str.rbegin(), str.rend(), ::isspace);
  str.erase(it.base(), str.end());
  return str;
}

}  // namespace pda
