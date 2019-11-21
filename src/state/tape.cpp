#include "tape.hpp"

namespace pda {

Tape::Tape(const std::string& input_str) {
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
  return tape_head_ >= -1 && tape_head_ < size() - 1;
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

  os << "]";

  return os;
}

}  // namespace pda
