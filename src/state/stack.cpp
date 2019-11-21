#include "stack.hpp"

namespace pda {

Alphabet& Stack::alphabet() {
  return alphabet_;
}
const Alphabet& Stack::alphabet() const {
  return alphabet_;
}

}  // namespace pda
