#pragma once

#include <string>

class State {
public:
  explicit State(const std::string& name);

  std::string name() const;
  void setName(const std::string& name);

private:
  std::string name_;
};
