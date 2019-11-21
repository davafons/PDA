#include "alphabet.hpp"

namespace pda {

Alphabet::Alphabet() {}

void Alphabet::reset() {
  regex_str_ = "\\.";
}

void Alphabet::addSymbol(Symbol symbol) {
  regex_str_ += "|" + symbol;

  regex_ = std::regex(regex_str_);
}

template <typename Iter>
void Alphabet::setSymbols(Iter begin, Iter end) {
  reset();

  for (Iter it = begin; it != end; ++it) {
    addSymbol(*it);
  }
}

void Alphabet::setSymbols(const std::vector<Symbol>& symbols) {
  setSymbols(symbols.cbegin(), symbols.cend());
}

void Alphabet::setSymbols(const std::string& symbols_str) {
  reset();

  std::stringstream symbols_stream(symbols_str);

  Symbol symbol;
  while (symbols_stream >> symbol) {
    addSymbol(symbol);
  }
}

std::vector<Symbol> Alphabet::split(const std::string& str) {
  return {std::sregex_token_iterator(str.begin(), str.end(), regex_),
          std::sregex_token_iterator()};
}

}  // namespace pda
