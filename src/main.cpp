#include <functional>
#include <iostream>
#include <stack>
#include <string>

#include "state/alphabet.hpp"
#include "state/pda.hpp"

int main() {
  pda::Pda pda;

  pda.addStates("p q r");
  pda.tapeAlphabet().setSymbols("0 1");
  pda.stackAlphabet().setSymbols("0 1 S");

  pda.setStartState("p");
  pda.setStackStartSymbol("S");

  // pda.addTransition("q1", "a", "Z", "q2", {"A", "Z"});
  // pda.addTransition("q2", "a", "Z", "q1", {"A", "Z"});
  //
  // pda::Alphabet a;
  // a.setSymbols("A B C");
  //
  // std::vector<pda::Symbol> asdf = a.split("ABCAB.");
  //
  // std::cout << asdf.size() << std::endl;
  //
  // for (const auto &s : asdf) {
  //   std::cout << s << std::endl;
  // }

  return 0;
}
