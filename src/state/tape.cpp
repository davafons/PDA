#include "tape.hpp"

#include <iomanip>
#include <iostream>

namespace pda {

Tape::Tape(const std::string& input_str, const std::string& alphabet_str) {
  if (alphabet_str.empty()) {
    alphabet_.setSymbols(input_str);
  } else {
    alphabet_.setSymbols(alphabet_str);
  }

  setInputString(input_str);
}

Alphabet& Tape::alphabet() {
  return alphabet_;
}
const Alphabet& Tape::alphabet() const {
  return alphabet_;
}

int Tape::size() const {
  return tape_.size();
}

Symbol Tape::peek() const {
  return tape_[tape_head_];
}

void Tape::next() {
  ++tape_head_;
}

bool Tape::hasNext() const {
  return tape_head_ >= -1 && tape_head_ < size();
}

void Tape::reset() {
  tape_head_ = 0;
  tape_.clear();
}

void Tape::setInputString(const std::string& input_str) {
  tape_ = alphabet_.split(input_str);
}

std::ostream& operator<<(std::ostream& os, const Tape& t) {
  os << "[ ";

  for (const auto& s : t.tape_) {
    os << s << " ";
  }

  os << "]\n";

  os << std::setw(1 + (t.tape_head_ + 1) * 2) << "^";

  return os;
}

}  // namespace pda
