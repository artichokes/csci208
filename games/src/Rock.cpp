#include "Rock.h"

Rock::Rock() : Tool("Rock") { }

int Rock::fight(Tool *other) {
  if (other->getType() == "Rock")
    return 0;
  else if (other->getType() == "Paper")
    return 2;
  else if (other->getType() == "Scissors")
    return 1;
  else
    return -1;
}
