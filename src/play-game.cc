#include "game.h"
#include "log.h"

using namespace cards;

int main() {
  // NOTE(paris): A seed of 1000 will result in a tie.
  Game game;
  game.dealCards();
  log("Initial setup:");
  log("%s", game.toString().c_str());

  auto round = 0;
  while (!game.finished()) {
    log("--- Round %d ----", ++round);
    auto winnerId = game.playRound();
    log("Player %d won - resulting state:", winnerId);
    log("%s", game.toString().c_str());
  }
  log("-------");

  auto winners = game.winners();
  if (winners.size() > 1) {
    log("Player 1 and Player 2 tied. Final state:");
  } else {
    log("Player %d won. Final state:", winners[0]);
  }
  log("%s", game.toString().c_str());
  return 0;
}