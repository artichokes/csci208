#ifndef PAPER_H
#define PAPER_H

#include "Tool.h"

class Paper : public Tool {
 public:
  // Creates a Tool with the type Paper
  Paper();

  // Fights the Paper against another Tool
  // @return -1 if cannot fight, 0 if tie, 1 if this object wins, and 2 if the other object wins
  int fight(Tool *other);
};

#endif //PAPER_H
