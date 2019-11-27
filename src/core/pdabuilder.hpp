#pragma once

#include "core/pda.hpp"

namespace pda {

class PdaBuilder {
public:
  static Pda fromFile(const std::string& file_path);
};

}  // namespace pda
