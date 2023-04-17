#include "player.h"

#include "log.h"

namespace cards {

void Player::addCardToTop(const Card &card) { cards_.push_back(card); }

const Card &Player::topCard() const {
  if (cards_.empty()) {
    log("[player@topCard] No cards so returning a default card.");
    return {};
  }
  return cards_.back();
}

void Player::discardTopCard() {
  if (cards_.empty()) {
    log("[player@discardTopCard] No cards so no-op.");
    return;
  }
  cards_.pop_back();
}

int Player::numCards() const { return cards_.size(); }

void Player::recordWin() { wins_++; }
int Player::wins() const { return wins_; }

void Player::recordLoss() { losses_++; }
int Player::losses() const { return losses_; }

std::string Player::toString() const {
  // TODO(paris): Could implement a format() function using sprintf() to make
  // this cleaner.
  auto s = std::to_string(cards_.size()) + " cards, " + std::to_string(wins_)
    + " wins, " + std::to_string(losses_) + " losses. Cards: [";
  for (int i = 0; i < cards_.size(); ++i) {
    s += cards_[i].toString();
    if (i < cards_.size() - 1) {
      s += ", ";
    }
  }
  s += "]";
  return s;
}

const std::vector<Card> &Player::cards() const { return cards_; }

}  // namespace cards