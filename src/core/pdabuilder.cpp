#include "pdabuilder.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "utils/utils.hpp"

namespace pda {
/*!
 *  \class PdaBuilder
 *  \brief Class builder of Pda objects.
 */

/*!
 *  Construct a Pda from a file.
 */
Pda PdaBuilder::fromFile(const std::string& file_path) {
  std::ifstream file_stream(file_path);
  if (!file_stream.is_open()) {
    throw std::runtime_error("Can't read automata file: " + file_path);
  }

  Pda pda;

  pda.addStates(Utils::nextLine(file_stream));

  pda.tapeAlphabet().addSymbols(Utils::nextLine(file_stream));
  pda.stackAlphabet().addSymbols(Utils::nextLine(file_stream));

  pda.setStartState(Utils::nextLine(file_stream));
  pda.setStackStartSymbol(Utils::nextLine(file_stream));

  // At this point, there's a line that is hard to parse:
  // On a "Final state PDA" file, this line says which are the final states.
  // On a "Empty stack PDA" file, the "final states" line isn't present, so this line is
  // alredy the first transtion.

  // So, we check if the symbols read on this line are states or not in order to guess
  // the type of the PDA.
  std::string conflictive_line = Utils::nextLine(file_stream);
  std::stringstream line_stream(conflictive_line);
  std::string token;
  bool is_states_line = true;
  while (line_stream >> token && is_states_line) {
    if (!pda.hasState(token)) {
      is_states_line = false;
    }
  }

  // Set the PDA type
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
