#include "alphabet.hpp"

#include <iostream>  // TODO: Delete

namespace pda {

/*!
 *  \class Alphabet
 *  \brief Set of symbols used for splitting strings.
 *
 *  Use this class to split a string by its recogizable symbols.
 *
 *  For example, for the following alphabet:
 *        A BC D
 *  The input string "ABCDFA" will be splitted in:
 *      [ A BC D A ]
 *
 *  (Note how unrecognized symbols like F are skipped)
 *  (Also, note how even if the string doesn't has spaces, the symbol BD is recognized
 *  as a whole)
 *
 *  By default, all alphabets include the Lambda symbol.
 */

/*!
 *  Check if the alphabet is empty.
 */
bool Alphabet::empty() const noexcept {
  return size_ == 0;
}

/*!
 *  Return the size of the alphabet.
 */
size_t Alphabet::size() const noexcept {
  return size_;
}

/*!
 *  Remove all symbols from the alphabet (leaving only the lambda).
 */
void Alphabet::reset() {
  regex_str_ = "\\" + Utils::lambda;
  regex_ = std::regex(regex_str_);

  size_ = 0;
}

/*!
 *  Add a new symbol to the Alphabet.
 */
void Alphabet::addSymbol(Symbol symbol) {
  regex_str_ += "|" + symbol;

  regex_ = std::regex(regex_str_);

  ++size_;
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
  std::vector<Symbol> matches;

  // Prints a warning message if a symbol was skipped due to not being on the Alphabet.
  auto check_sticky = [](int init_pos, int end_pos, const std::string& symbols_str) {
    if (init_pos != end_pos) {
      std::cout << "WARGNING! Unrecognized symbol: "
                << symbols_str.substr(init_pos, end_pos - init_pos) << std::endl;
    }
  };

  int current_pos = 0;
  for (auto it = std::sregex_iterator(symbols_str.begin(), symbols_str.end(), regex_);
       it != std::sregex_iterator();
       ++it) {

    // Push the current match to the symbols vector
    matches.push_back(it->str());

    // Check if we skipped some symbol between matches
    check_sticky(current_pos, it->position(), symbols_str);
    current_pos = it->position() + it->length();
  }

  check_sticky(current_pos, symbols_str.length(), symbols_str);

  return matches;
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
