#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <iostream>
#include "Card.h"
#include "Deck.h"

class MagicCard {
 public:
  MagicCard();

 private:
  Deck deck;
  Card card;

  void convertCardToQueenOfHearts(Card &card);
};

#endif //MAGICCARD_H
