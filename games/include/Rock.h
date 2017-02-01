#ifndef ROCK_H
#define ROCK_H

#include "Tool.h"

class Rock : public Tool {
 public:
  // Creates a Tool with the type Rock
  Rock();

  // Fights the Rock against another Tool
  // @return -1 if cannot fight, 0 if tie, 1 if this object wins, and 2 if the other object wins
  int fight(Tool *other);
};

#endif //ROCK_H
