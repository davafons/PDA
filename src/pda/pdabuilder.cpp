#include "pdabuilder.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "utils/utils.hpp"

namespace pda {

Pda PdaBuilder::fromFile(const std::string& file_path) {
  std::ifstream file_stream(file_path);

  auto next_line = [](std::ifstream& file_stream) {
    std::string line;
    do {
      std::getline(file_stream, line);
    } while (Utils::trim(line)[0] == '#');

    return line;
  };

  Pda pda;

  pda.addStates(next_line(file_stream));

  pda.tapeAlphabet().setSymbols(next_line(file_stream));
  pda.stackAlphabet().setSymbols(next_line(file_stream));

  pda.setStartState(next_line(file_stream));
  pda.setStackStartSymbol(next_line(file_stream));

  // This line is hard to parse. Check if the line has all states or starting a
  // transition

  std::string conflictive_line = next_line(file_stream);
  std::stringstream line_stream(conflictive_line);
  std::string token;
  bool is_states_line = true;
  while (line_stream >> token && is_states_line) {
    if (!pda.hasState(token)) {
      is_states_line = false;
    }
  }

  if (is_states_line) {
    pda.setPdaType(Pda::Type::FinalState);
    pda.setFinalStates(conflictive_line);
  } else {
    pda.setPdaType(Pda::Type::EmptyStack);
    pda.addTransition(conflictive_line);
  }

  // Read transitions
  std::string transition_line;
  while (std::getline(file_stream, transition_line)) {
    pda.addTransition(transition_line);
  }

  return pda;
}
}  // namespace pda
