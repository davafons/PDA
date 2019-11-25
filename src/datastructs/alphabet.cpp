#include "alphabet.hpp"

namespace pda {

bool Alphabet::empty() const {
  return regex_str_ == "\\" + Utils::lambda;
}

void Alphabet::reset() {
  regex_str_ = "\\" + Utils::lambda;
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
  setSymbols(Utils::split(symbols_str));
}

std::vector<Symbol> Alphabet::splitInSymbols(const std::string& symbols_str) {
  return {std::sregex_token_iterator(symbols_str.begin(), symbols_str.end(), regex_),
          std::sregex_token_iterator()};
}

}  // namespace pda
