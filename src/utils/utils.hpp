#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace pda {

using Symbol = std::string;

class Utils {
public:
  static const Symbol lambda;

  static std::vector<std::string> split(const std::string& str);

  static std::string& trim(std::string& str);
  static std::string& ltrim(std::string& str);
  static std::string& rtrim(std::string& str);
};

}  // namespace pda
