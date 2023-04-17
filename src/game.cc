
#include "game.h"

#include <algorithm>

namespace cards {

Game::Game(int deckSize, unsigned long rngSeed)
    : rng_(rngSeed), deckSize_(deckSize) {
  if (deckSize % 2 != 0) {
    log(
      "[game@constructor] Warning - deckSize (%d) is odd. Will round down and "
      "deal %d cards to each player.",
      deckSize,
      numCardsPerPlayer());
  }
}

void Game::dealCards() {
  // Create a deck of shuffled cards.
  std::vector<int> deck;
  deck.reserve(deckSize_);
  for (int i = 1; i <= deckSize_; ++i) {
    deck.push_back(i);
  }
  std::shuffle(deck.begin(), deck.end(), rng_);

  // Deal to players.
  auto cardsPerPlayer = numCardsPerPlayer();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < cardsPerPlayer; ++j) {
      Card card = {deck[i * cardsPerPlayer + j]};
      players_[i].addCardToTop(card);
    }
  }
}

int Game::playRound() {
  // First get the top card from each player and have them discard their top
  // card.
  std::vector<std::pair<int, int>> cards;
  cards.reserve(players_.size());
  for (auto playerId = 0; playerId < players_.size(); playerId++) {
    const auto &card = players_[playerId].topCard();
    cards.push_back({card.number, playerId});
    players_[playerId].discardTopCard();
  }

  // Then determine the winner.
  auto winnerId = std::max_element(cards.begin(), cards.end())->second;

  // Finally for each player record whether they won or lost.
  for (int playerId = 0; playerId < players_.size(); playerId++) {
    playerId == winnerId ? players_[playerId].recordWin()
                         : players_[playerId].recordLoss();
  }

  return winnerId;
}

bool Game::finished() const {
  for (const auto &player : players_) {
    if (player.numCards() == 0) {
      return true;
    }
  }
  return false;
}

std::vector<int> Game::winners() const {
  // NOTE(paris): Could have playRound() update this so here we could return a
  // const ref.
  std::vector<int> winners;
  int max = 0;
  for (int playerId = 0; playerId < players_.size(); playerId++) {
    auto wins = players_[playerId].wins();
    if (wins > max) {
      winners = {playerId};
      max = wins;
    } else if (wins == max) {
      winners.push_back(playerId);
    } else {
    }
  }
  return winners;
}

int Game::numCardsPerPlayer() const { return deckSize_ / 2; }

std::string Game::toString() const {
  std::string s = "";
  for (int playerId = 0; playerId < players_.size(); ++playerId) {
    s += "Player " + std::to_string(playerId) + ": "
      + players_[playerId].toString();
    if (playerId < players_.size() - 1) {
      s += "\n";
    }
  }
  return s;
}

const std::vector<Player> &Game::players() const { return players_; }

}  // namespace cards