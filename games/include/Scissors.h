#ifndef SCISSORS_H
#define SCISSORS_H

#include "Tool.h"

class Scissors : public Tool {
 public:
  // Creates a Tool with the type Scissors
  Scissors();

  // Fights the Scissors against another Tool
  // @return -1 if cannot fight, 0 if tie, 1 if this object wins, and 2 if the other object wins
  int fight(Tool *other);
};

#endif //SCISSORS_H
