#include <functional>
#include <iostream>
#include <stack>
#include <string>

#include "state/alphabet.hpp"
#include "state/pda.hpp"

int main() {
  pda::Pda pda;

  pda.addStates("q1 q2");
  pda.tapeAlphabet().setSymbols("a b");
  pda.stackAlphabet().setSymbols("S A");

  pda.setStartState("q1");
  pda.setStackStartSymbol("S");

  pda.addTransition("q1", "a", "S", "q1", "A");
  pda.addTransition("q1", "a", "A", "q1", "A A");
  pda.addTransition("q1", "b", "A", "q2", ".");
  pda.addTransition("q2", "b", "A", "q2", ".");

  bool result = pda.run("aabb");

  std::cout << result << std::endl;

  return 0;
}
