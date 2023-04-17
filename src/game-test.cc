#include "game.h"

#include <unordered_set>

#include "gtest/gtest.h"

namespace cards {

TEST(GameTest, CleanInit) {
  Game g;
  const auto &players = g.players();
  EXPECT_EQ(players.size(), 2);
  for (const auto &player : players) {
    EXPECT_EQ(player.numCards(), 0);
    EXPECT_EQ(player.wins(), 0);
    EXPECT_EQ(player.losses(), 0);
  }
}

TEST(GameTest, DealCards) {
  auto deckSize = 52;
  Game g(deckSize);
  g.dealCards();
  const auto &players = g.players();
  const auto &player0 = players[0];
  const auto &player1 = players[1];

  // Player 0 and Player 1 should have the same number of cards.
  EXPECT_EQ(player0.numCards(), player1.numCards());

  // Player 0 and Player 1 should share no cards.
  std::unordered_set<int> player0Cards;
  for (const auto &card : player0.cards()) {
    player0Cards.insert(card.number);
  }
  for (const auto &card : player1.cards()) {
    EXPECT_EQ(player0Cards.count(card.number), 0);
  }
}

TEST(GameTest, ZeroDeckSize) {
  auto deckSize = 0;
  Game g(deckSize);

  // We are immediately finished.
  EXPECT_TRUE(g.finished());
  EXPECT_EQ(g.winners().size(), 2);

  // We don't crash.
  g.dealCards();
  g.playRound();
  g.finished();
  g.winners();
}

TEST(GameTest, PlayGame) {
  Game g;
  g.dealCards();
  const auto &players = g.players();
  const auto &player0 = players[0];
  const auto &player1 = players[1];

  auto winnerId = g.playRound();
  if (winnerId == 0) {
    EXPECT_EQ(player0.wins(), 1);
    EXPECT_EQ(player1.losses(), 1);
  } else {
    EXPECT_EQ(player0.losses(), 1);
    EXPECT_EQ(player1.wins(), 1);
  }
  EXPECT_FALSE(g.finished());

  g.playRound();
  EXPECT_EQ(player0.wins() + player1.wins(), 2);
  EXPECT_EQ(player0.losses() + player1.losses(), 2);
  EXPECT_FALSE(g.finished());
}

TEST(GameTest, FinishGame) {
  Game g(4);
  g.dealCards();
  g.playRound();
  EXPECT_FALSE(g.finished());
  g.playRound();
  EXPECT_TRUE(g.finished());
  auto winners = g.winners();
  EXPECT_EQ(winners.size(), 1);
  // NOTE(paris): Safe to hard-code the winner b/c we have a fixed seed. If that
  // changes this test will fail.
  EXPECT_EQ(winners[0], 1);
}

}  // namespace cards