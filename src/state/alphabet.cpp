#include "alphabet.hpp"

namespace pda {

Alphabet::Alphabet() {}

void Alphabet::addSymbol(Symbol symbol) {
  regex_str_ += "|" + symbol;

  regex_ = std::regex(regex_str_);
}

template <typename Iter>
void Alphabet::addSymbols(Iter begin, Iter end) {
  for (Iter it = begin; it != end; ++it) {
    addSymbol(*it);
  }
}

void Alphabet::addSymbols(const std::vector<Symbol>& symbols) {
  addSymbols(symbols.cbegin(), symbols.cend());
}

std::vector<Symbol> Alphabet::split(const std::string& str) {
  return {std::sregex_token_iterator(str.begin(), str.end(), regex_),
          std::sregex_token_iterator()};
}

}  // namespace pda
