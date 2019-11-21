#pragma once

#include <vector>

#include "utils.hpp"

namespace pda {

class Tape {
public:
  explicit Tape(const std::string& input_str = "");

  int size() const;

  Symbol peek() const;

  void next();
  bool hasNext() const;

  void reset();

  void setInputString(const std::string& input_str);

  friend std::ostream& operator<<(std::ostream& os, const Tape& tape);

private:
  std::vector<Symbol> tape_;

  int tape_head_{0};
};

}  // namespace pda
