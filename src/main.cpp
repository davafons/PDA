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

  pda.setFinalSymbols("r");

  pda.addTransition("p", "0", "S", "p", "0 S");
  pda.addTransition("p", "1", "S", "p", "1 S");
  pda.addTransition("p", "0", "0", "p", "0 0");
  pda.addTransition("p", "0", "1", "p", "0 1");
  pda.addTransition("p", "1", "1", "p", "1 1");

  return 0;
}
