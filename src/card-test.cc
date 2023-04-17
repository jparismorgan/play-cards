#include "card.h"
#include "gtest/gtest.h"

namespace cards {

TEST(CardTest, NoCrash) {
  Card c;
  c.number = 1;
}

}  // namespace cards