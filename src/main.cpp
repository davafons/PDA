#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

#include "pda/pda.hpp"
#include "pda/pdabuilder.hpp"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " pda.txt input_string" << std::endl;
    return 1;
  }

  pda::Pda pushdown_automata = pda::PdaBuilder::fromFile(argv[1]);

  std::cout << pushdown_automata << std::endl;

  std::cout << "Running: " << argv[1] << "..." << std::endl;

  bool result = pushdown_automata.run(argv[2]);
  std::cout << "Result: " << std::boolalpha << result << std::endl;

  return 0;
}
