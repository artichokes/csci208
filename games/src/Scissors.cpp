#include "Scissors.h"

Scissors::Scissors() : Tool("Scissors") { }

int Scissors::fight(Tool *other) {
  if (other->getType() == "Rock")
    return 2;
  else if (other->getType() == "Paper")
    return 1;
  else if (other->getType() == "Scissors")
    return 0;
  else
    return -1;
}
