#include "tape.hpp"

#include <iomanip>
#include <iostream>

namespace pda {

/*!
 *  \class Tape
 *  \brief Tape (input string) used by the PDA
 *
 *  All symbols on the Tape must be recognized by the alphabet.
 */

/*!
 *  Construct a Tape object.
 *
 *  The alphabet is deducted from the input string if no alphabet is passed to the
 *  constructor. Otherwise, its used.
 */
Tape::Tape(const std::string& input_str, const std::string& alphabet_str) {
  if (alphabet_str.empty()) {
    alphabet_.addSymbols(input_str);
  } else {
    alphabet_.addSymbols(alphabet_str);
  }

  setInputString(input_str);
}

/*!
 *  Return the alphabet associated with this tape.
 */
Alphabet& Tape::alphabet() {
  return alphabet_;
}

/*!
 *  Return the alphabet associated with this tape.
 */
const Alphabet& Tape::alphabet() const {
  return alphabet_;
}

/*!
 *  Return the size (number of symbols) of the tape.
 */
int Tape::size() const {
  return tape_.size();
}

/*!
 *  Return the symbol currently being pointed by the tape head.
 *  WARNING: Always check if the tape has more symbols before. Otherwise its undefined
 *  behaviour.
 *
 *  \sa has
 */
Symbol Tape::peek() const {
  return tape_[tape_head_];
}

/*!
 *  Move the tape head to the next position on the input string.
 */
void Tape::next() {
  ++tape_head_;
}

/*!
 *  Check if the tape head is pointing to a readable symbol.
 */
bool Tape::canRead() const {
  return tape_head_ >= -1 && tape_head_ < size();
}

/*!
 *  Clear the tape and reset the head to the initial position.
 */
void Tape::reset() {
  tape_head_ = 0;
  tape_.clear();
}

/*!
 *  Set a new input string to the tape.
 *  The input string will be splitted in symbols according to the alphabet.
 */
void Tape::setInputString(const std::string& input_str) {
  tape_head_ = 0;
  tape_ = alphabet_.splitInSymbols(input_str);
}

/*!
 *  Print the tape elements.
 */
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
