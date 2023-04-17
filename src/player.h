#pragma once

#include <string>
#include <vector>

#include "card.h"

namespace cards {

// A class for a player who 1) manages their own hand of cards 2) keeps track of
// their wins / losses.
class Player {
public:
  // Adds a card to the top of the hand.
  // @param card The card.
  void addCardToTop(const Card &card);
  // @returns card The top card.
  const Card &topCard() const;
  // Discard the top card from the player's hand.
  void discardTopCard();

  // @returns The number of cards in the player's hand.
  int numCards() const;

  // Record that the player won.
  void recordWin();
  // @returns The total number of wins the player has recorded.
  int wins() const;

  // Record that the player lost.
  void recordLoss();
  // @returns The total number of losses the player has recorded.
  int losses() const;

  // ---------------- Debugging Methods ----------------
  std::string toString() const;
  const std::vector<Card> &cards() const;

private:
  // First element in vector is the bottom, last element is the top.
  std::vector<Card> cards_;
  int wins_ = 0;
  int losses_ = 0;
};

}  // namespace cards