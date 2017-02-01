#ifndef DECK_H
#define DECK_H

#include <array>
#include <random>
#include "Card.h"

class Deck {
 public:
  // Creates a new unshuffled 52 card deck without jokers
  Deck();
  // Deletes the cards and the deck
  ~Deck();

  // Shuffles the deck
  void shuffle();
  // Picks the "top" card from the deck
  // @return A pointer to the card or nullptr if no more cards
  Card *pick();
  // Picks a random card from the deck
  // @return A pointer to the card or nullptr if no more cards
  Card *pick_random();
 private:
  std::array<Card *, 52> card;
  std::default_random_engine generator;
  std::uniform_int_distribution<size_t> distribution = std::uniform_int_distribution<size_t>(0, 51);

  // Picks a card from the deck at the given index
  // removing the card from the deck
  // @return A pointer to the card, nullptr if no more cards, or nullptr if index >= 52
  Card *pick(size_t index);
};

#endif //DECK_H
