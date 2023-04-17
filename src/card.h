#pragma once

#include <string>

struct Card {
  int number = 0;

  // ---------------- Debugging Methods ----------------
  std::string toString() const { return std::to_string(number); }
};
