#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "Card.h"
#include "Deck.h"

class BlackJack {
 public:
  // Starts a new game of BlackJack
  void play();

 private:
  Deck *deck;
  unsigned house_hand = 0;
  unsigned player_hand = 0;

  // Converts a card to a point value
  // Ace = 1, Face Cards = 10
  // @param card a card
  // @return The point value of a card
  size_t cardToPoints(const Card &card);

  // Deal two cards to each the house and player
  void initial_deal();
  // Prompts the player to take a hit
  void player_turn();
  // Determines if the house should hit
  void house_turn();
  // Outputs the winner of the match
  void winner();
};

#endif //BLACKJACK_H
