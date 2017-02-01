#include "DiscardPile.h"

DiscardPile::DiscardPile() : Stack<Card>(), suit(Suit::Joker) { }

Suit DiscardPile::getSuit() {
  return this->suit;
}

void DiscardPile::setSuit(Suit newSuit) {
  this->suit = newSuit;
}
