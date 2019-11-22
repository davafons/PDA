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

  pda.setFinalStates("r");

  pda.addTransition("p", "0", "S", "r", "0 S");

  std::cout << pda.run("0") << std::endl;

  return 0;
}
