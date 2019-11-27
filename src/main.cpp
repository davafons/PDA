#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

#include "boost/program_options.hpp"
#include "core/pda.hpp"
#include "core/pdabuilder.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  po::options_description desc("Options");

  // Options
  bool debug_mode = false;
  std::string automata_file;
  std::string input;

  desc.add_options()("help,h", "Show help menu")(
      "FILE",
      po::value<std::string>(&automata_file)->required(),
      "Automata definition")(

      "debug,D", po::bool_switch(&debug_mode), "Show a trace of the execution")(

      "INPUT",
      po::value<std::string>(&input)->required(),
      "Input string or file to be recognized by the automata.");

  po::variables_map vm;

  try {
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << "Pushdown Automata (PDA) implementation in C++\n" << std::endl;
      std::cout << desc << std::endl;
      return 0;
    }

    po::notify(vm);

    pda::Pda pushdown_automata = pda::PdaBuilder::fromFile(automata_file);
    pushdown_automata.setDebugMode(debug_mode);

    bool recognized = pushdown_automata.run(input);
    std::cout << "Recognized: " << std::boolalpha << recognized << std::endl;

  } catch (const po::error& e) {
    std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
    std::cerr << desc << std::endl;
    return 1;
  }

  return 0;
}
