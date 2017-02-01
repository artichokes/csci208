#ifndef RPS_H
#define RPS_H

#include <random>
#include <algorithm>

#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

// A game of Rock-Paper-Scissors
class RPS {
 public:
  // Starts a new game of Rock-Paper-Scissors
  RPS();

 private:
  // Prompts the player for a Tool
  // @return The Tool the player selected
  Tool *playerTurn();

  // Picks a random Tool for the Computer
  // @return The Tool the computer selected
  Tool *computerTurn();
};

#endif //RPS_H
