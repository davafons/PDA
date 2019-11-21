#include "alphabet.hpp"

namespace pda {

Alphabet::Alphabet() {}

bool Alphabet::empty() const {
  return regex_str_ == "\\.";
}

void Alphabet::reset() {
  regex_str_ = "\\.";
}

void Alphabet::addSymbol(Symbol symbol) {
  regex_str_ += "|" + symbol;

  regex_ = std::regex(regex_str_);
}

void Alphabet::setSymbols(const std::vector<Symbol>& symbols) {
  for (const auto& symbol : symbols) {
    addSymbol(symbol);
  }
}

void Alphabet::setSymbols(const std::string& symbols_str) {
  setSymbols(splitSymbols(symbols_str));
}

std::vector<Symbol> Alphabet::split(const std::string& str) {
  return {std::sregex_token_iterator(str.begin(), str.end(), regex_),
          std::sregex_token_iterator()};
}

}  // namespace pda
