#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H

#include "Hand.h"
#include "Deck.h"
#include "DiscardPile.h"

class CrazyEights {
 public:
  CrazyEights();

 private:
  Deck deck;
  DiscardPile discardPile;

  Hand player;
  Hand computer;

  // Deals the players 7 cards each
  void dealCards();

  // Shows the top discarded card
  void showLastDiscarded();

  // Shows the player's hand
  void showPlayerHand();

  // Shows the computer's hand
  void showComputerHand();

  // Prompts the user for their turn
  void playerTurn();

  // Prompts the player for a suit
  void chooseSuit();

  // Prints the winner as the player
  void playerWins();

  // Plays the computers turn
  void computerTurn();

  // Prints the winner as the computer
  void computerWins();

  // Converts cards to points
  // @return the point value of the card
  int cardToPoints(const Card &card);

  // Scores the hand
  // @return the point value of the hand
  int scoreHand(const Hand &hand);

  // Compares the scores of each hand to determing the winner
  void compareScores();
};

#endif //CRAZYEIGHTS_H
