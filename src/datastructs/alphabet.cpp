#include "alphabet.hpp"

namespace pda {

/*!
 *  \class Alphabet
 *  \brief Set of symbols used for splitting strings.
 *
 *  Use this class to split a string by its recogizable symbols. Each symbol will be
 *  recognizable, even if it doesn't has spaces in between.
 *
 *  For example, for the following alphabet:
 *        A BC D
 *  The input string "ABCDFA" will be splitted in:
 *      [ A BC D A ]
 *
 *  (Note how unrecognized symbols like F are skipped)
 *
 *  By default, all alphabets include the Lambda symbol.
 */

/*!
 *  Check if the alphabet is empty.
 */
bool Alphabet::empty() const {
  return regex_str_ == "\\" + Utils::lambda;
}

/*!
 *  Remove all symbols from the alphabet (leaving only the lambda).
 */
void Alphabet::reset() {
  regex_str_ = "\\" + Utils::lambda;
}

/*!
 *  Add a new symbol to the Alphabet.
 */
void Alphabet::addSymbol(Symbol symbol) {
  regex_str_ += "|" + symbol;

  regex_ = std::regex(regex_str_);
}

/*!
 *  Add a new set of symbols to the Alphabet.
 *  Note: The new symbols must be separated by a whitespace.
 */
void Alphabet::addSymbols(const std::string& symbols_str) {
  for (const auto& symbol : Utils::split(symbols_str)) {
    addSymbol(symbol);
  }
}

/*!
 *  Use the Alphabet to split the input symbol on a vector of individual Symbols.
 *  Note: Unrecognized elements are skipped.
 */
std::vector<Symbol> Alphabet::splitInSymbols(const std::string& symbols_str) {
  return {std::sregex_token_iterator(symbols_str.begin(), symbols_str.end(), regex_),
          std::sregex_token_iterator()};
}

/*!
 *  Print the content of the alphabet (Splitted by whitespaces)
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  std::string alphabet_symbols(alphabet.regex_str_);
  std::replace(alphabet_symbols.begin(), alphabet_symbols.end(), '|', ' ');

  os << alphabet_symbols;

  return os;
}

}  // namespace pda
