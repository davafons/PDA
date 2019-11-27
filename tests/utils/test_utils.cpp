#include "gtest/gtest.h"
#include "utils/utils.hpp"

namespace pda {

TEST(Utils, Split) {
  auto result = Utils::split("a bc d");

  ASSERT_EQ(result.size(), 3);
  ASSERT_EQ(result[0], "a");
  ASSERT_EQ(result[1], "bc");
  ASSERT_EQ(result[2], "d");
}

TEST(Utils, LTrim) {
  std::string str = "  hola  ";
  Utils::ltrim(str);

  ASSERT_EQ(str, "hola  ");
}

TEST(Utils, RTrim) {
  std::string str = "  hola  ";
  Utils::rtrim(str);

  ASSERT_EQ(str, "  hola");
}

TEST(Utils, Trim) {
  std::string str = "  hola  ";
  Utils::trim(str);

  ASSERT_EQ(str, "hola");
}

}  // namespace pda
