#include "player.h"

#include "gtest/gtest.h"

namespace cards {

TEST(PlayerTest, NumCards) {
  Player p;
  p.addCardToTop({});
  EXPECT_EQ(p.numCards(), 1);
  EXPECT_EQ(p.numCards(), p.cards().size());

  p.addCardToTop({});
  EXPECT_EQ(p.numCards(), 2);
  EXPECT_EQ(p.numCards(), p.cards().size());
}

TEST(PlayerTest, AddDiscardCards) {
  Player p;
  p.addCardToTop({1});
  EXPECT_EQ(p.numCards(), 1);
  EXPECT_EQ(p.topCard().number, 1);
  EXPECT_EQ(p.wins(), 0);
  EXPECT_EQ(p.losses(), 0);

  p.addCardToTop({2});
  EXPECT_EQ(p.numCards(), 2);
  EXPECT_EQ(p.topCard().number, 2);
  EXPECT_EQ(p.wins(), 0);
  EXPECT_EQ(p.losses(), 0);

  p.discardTopCard();
  EXPECT_EQ(p.numCards(), 1);
  EXPECT_EQ(p.topCard().number, 1);
  EXPECT_EQ(p.wins(), 0);
  EXPECT_EQ(p.losses(), 0);

  p.discardTopCard();
  EXPECT_EQ(p.numCards(), 0);
  EXPECT_EQ(p.wins(), 0);
  EXPECT_EQ(p.losses(), 0);
}

TEST(PlayerTest, NoCrashOnEmptyDeck) {
  Player p;
  p.discardTopCard();
  p.discardTopCard();

  p.topCard();
  p.topCard();
}

TEST(PlayerTest, RecordWinLoss) {
  Player p;
  p.recordWin();
  EXPECT_EQ(p.wins(), 1);
  EXPECT_EQ(p.losses(), 0);

  p.recordLoss();
  EXPECT_EQ(p.wins(), 1);
  EXPECT_EQ(p.losses(), 1);

  p.recordLoss();
  EXPECT_EQ(p.wins(), 1);
  EXPECT_EQ(p.losses(), 2);

  p.recordWin();
  EXPECT_EQ(p.wins(), 2);
  EXPECT_EQ(p.losses(), 2);
}

}  // namespace cards