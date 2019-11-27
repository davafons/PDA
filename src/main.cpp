#include <boost/program_options.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "core/pda.hpp"
#include "core/pdabuilder.hpp"
#include "utils/utils.hpp"

namespace po = boost::program_options;

struct Options {
  bool debug_mode{false};
  std::string pda_file{""};
  std::string input{""};
};

void runAutomata(pda::Pda& pda, const std::string& input);
bool parseArguments(int argc, char* argv[], Options& options);

int main(int argc, char* argv[]) {
  // Options
  Options options;

  if (!parseArguments(argc, argv, options)) {
    return 1;
  }

  try {
    // Instantiate PDA from file
    pda::Pda pda = pda::PdaBuilder::fromFile(options.pda_file);
    pda.setDebugMode(options.debug_mode);

    // Try to open the input as a file. If fails, execute is as an input sequence.
    std::ifstream input_file(options.input);
    if (input_file.is_open()) {

      // Run the automata for each line.
      std::string line = pda::Utils::nextLine(input_file);

      while (!line.empty()) {
        runAutomata(pda, line);
        line = pda::Utils::nextLine(input_file);
      }

    } else {  // Run the input as a string if couldn't be opened as a file
      runAutomata(pda, options.input);
    }

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}

void runAutomata(pda::Pda& pda, const std::string& input) {
  std::cout << "Input: " << input << std::endl;
  bool recognized = pda.run(input);
  std::cout << "Recognized: " << std::boolalpha << recognized << std::endl;
}

bool parseArguments(int argc, char* argv[], Options& options) {
  po::options_description desc("Options");
  desc.add_options()("help,h", "Show help menu")(
      "FILE",
      po::value<std::string>(&options.pda_file)->required(),
      "Automata definition")(

      "debug,D", po::bool_switch(&options.debug_mode), "Show a trace of the execution")(

      "INPUT",
      po::value<std::string>(&options.input)->required(),
      "Input string or file to be recognized by the automata.");

  try {
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);

    if (vm.count("help")) {
      std::cout << "Pushdown Automata (PDA) implementation in C++\n" << std::endl;
      std::cout << desc << std::endl;
      return false;
    }

    po::notify(vm);

  } catch (const po::error& e) {
    std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
    std::cerr << desc << std::endl;
    return false;
  }

  return true;
}
