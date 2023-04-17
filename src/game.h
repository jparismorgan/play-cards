#pragma once

#include <random>
#include <vector>

#include "card.h"
#include "log.h"
#include "player.h"

namespace cards {

// A class containing a two-player game similar to War.
class Game {
public:
  Game(int deckSize = 52, unsigned long rngSeed = 0);

  // Deal cards for the game.
  void dealCards();

  // Play a round of the game and determine the winner. If it is a tie the first
  // player to play wins.
  // @returns The ID of the player who won the round.
  int playRound();

  // @returns True if the game is finished, false otherwise.
  bool finished() const;

  // Return the current winner of the game, or winners if multiple players are
  // tied.
  // @returns A list containg the IDs of the player(s) who are currently
  // winning.
  std::vector<int> winners() const;

  // ---------------- Debugging Methods ----------------
  std::string toString() const;
  const std::vector<Player> &players() const;

private:
  // @returns The number of cards each player will be dealt.
  int numCardsPerPlayer() const;

  std::default_random_engine rng_;
  const int deckSize_ = 0;
  std::vector<Player> players_ = {{}, {}};
};

}  // namespace cards