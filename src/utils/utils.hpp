#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace pda {

using Symbol = std::string;

class Utils {
public:
  static const std::string lambda;

  static std::vector<std::string> split(const std::string& str);
};

}  // namespace pda
