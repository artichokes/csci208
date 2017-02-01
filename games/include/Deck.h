#ifndef DECK_H
#define DECK_H

#include <stdexcept>
#include "Card.h"
#include "Stack.h"

class Deck: private Stack<Card> {
 public:
  // Creates an unshuffled 52 card deck without jokers
  Deck();

  // Shuffles the deck
  void shuffle();
  // Picks the "top" card from the deck
  // @return A the card or throws DeckEmptyException if no more cards
  Card draw();

  // Exceptions
  class DeckEmptyException;
};

class Deck::DeckEmptyException: public runtime_error {
 public:
  DeckEmptyException() : runtime_error("Deck is empty") { }
};

#endif //DECK_H
