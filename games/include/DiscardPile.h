#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "Stack.h"
#include "Card.h"

class DiscardPile: public Stack<Card> {
 public:
  DiscardPile();

  Suit getSuit();
  void setSuit(Suit newSuit);
 private:
  Suit suit;
};

#endif //DISCARDPILE_H
