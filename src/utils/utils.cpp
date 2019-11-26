#include "utils.hpp"

#include <algorithm>

namespace pda {

/*!
 *  \class Utils
 *  \brief Utility methods and objects.
 */

/*!
 *  Symbol used to represent "lambda".
 */
const Symbol Utils::lambda = ".";

/*!
 *  Split a string using whitespaces as delimiter.
 */
std::vector<std::string> Utils::split(const std::string& str) {
  std::vector<Symbol> result;

  std::stringstream symbols_stream(str);

  Symbol symbol;
  while (symbols_stream >> symbol) {
    result.push_back(symbol);
  }

  return result;
}

/*!
 *  Remove all whitespaces at the start and end of the string.
 */
std::string& Utils::trim(std::string& str) {
  return ltrim(rtrim(str));
}

/*!
 *  Remove all whitespaces at the start of the string.
 */
std::string& Utils::ltrim(std::string& str) {
  auto it = std::find_if_not(str.begin(), str.end(), ::isspace);
  str.erase(str.begin(), it);
  return str;
}

/*!
 *  Remove all whitespaces at the end of the string.
 */
std::string& Utils::rtrim(std::string& str) {
  auto it = std::find_if_not(str.rbegin(), str.rend(), ::isspace);
  str.erase(it.base(), str.end());
  return str;
}

}  // namespace pda
