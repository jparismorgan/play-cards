#include "log.h"
#include "gtest/gtest.h"

namespace cards {

TEST(LogTest, NoCrash) {
  log("Test log.");
}

}  // namespace cards