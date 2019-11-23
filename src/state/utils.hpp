#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace pda {

namespace Constant {
const std::string lambda = ".";
}

using Symbol = std::string;

std::vector<Symbol> splitSymbols(const std::string& symbols_str);

}  // namespace pda
