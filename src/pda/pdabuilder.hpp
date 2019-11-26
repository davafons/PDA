#pragma once

#include "pda/pda.hpp"

namespace pda {

class PdaBuilder {
public:
  static Pda fromFile(const std::string& file_path);
};

}  // namespace pda
