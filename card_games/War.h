#ifndef WAR_H
#define WAR_H

#include "Deck.h"

class War {
 public:
  // Play rounds until the numbers of rounds or until out of cards
  void play(unsigned rounds = 10);

 private:
  Deck *deck;
  unsigned round = 1;
  unsigned player1_score = 0;
  unsigned player2_score = 0;

  // Plays a round
  // @return -1 if no more cards, 0 if tie, 1 if player 1 wins, or 2 if player 2 wins
  int play_round();
  // Outputs the current score
  void print_score();
  // Outputs the game results
  void print_results();
};

#endif //WAR_H
