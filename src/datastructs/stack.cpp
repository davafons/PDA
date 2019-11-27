#include "stack.hpp"

namespace pda {

/*!
 *  \class Stack
 *  \brief Stack used by the PDA
 *
 *  All symbols pushed to the stack must be recognized by the alphabet.
 */

/*!
 *  Check if the stack is empty.
 */
bool Stack::empty() const noexcept {
  return std::vector<Symbol>::empty();
}

/*!
 *  Return the size of the stack.
 */
size_t Stack::size() const noexcept {
  return std::vector<Symbol>::size();
}

/*!
 *  Remove all elements from the stack.
 */
void Stack::clear() {
  std::vector<Symbol>::clear();
}

/*!
 *  Return the character at the top of the stack.
 */
Symbol& Stack::top() {
  return std::vector<Symbol>::back();
}

/*!
 *  Return the character at the top of the stack.
 */
const Symbol& Stack::top() const {
  return std::vector<Symbol>::back();
}

/*!
 *  Delete the top element from the stack.
 *  Warning: Always check if the stack is not empty.
 *  Popping an element from an empty stack is undefined behaviour.
 */
void Stack::pop() {
  std::vector<Symbol>::pop_back();
}

/*!
 *  Clear the stack and set the passed element as the top.
 */
void Stack::setStartSymbol(const Symbol& symbol) {
  clear();

  std::vector<Symbol>::push_back(symbol);
}

/*!
 *  Insert new symbols onto the Stack.
 *  The string is splitted in symbols using the stack's alphabet.
 *  NOTE: The symbols are pushed from RIGHT to LEFT.
 */
void Stack::pushSymbols(const std::string& symbols_str) {
  auto symbols = alphabet_.splitInSymbols(symbols_str);

  for (auto symbol_it = symbols.crbegin(); symbol_it != symbols.crend(); ++symbol_it) {
    if (*symbol_it != Utils::lambda) {
      std::vector<Symbol>::push_back(*symbol_it);
    }
  }
}

/*!
 *  Return the alphabet associated with this stack.
 */
Alphabet& Stack::alphabet() {
  return alphabet_;
}

/*!
 *  Return the alphabet associated with this stack.
 */
const Alphabet& Stack::alphabet() const {
  return alphabet_;
}

/*!
 *  Print all the stack elements.
 */
std::ostream& operator<<(std::ostream& os, const Stack& st) {
  os << "{ ";

  for (auto it = st.crbegin(); it != st.crend(); ++it) {
    os << *it << " ";
  }

  os << "}";

  return os;
}

}  // namespace pda
