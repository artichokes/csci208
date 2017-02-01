#include "Paper.h"

Paper::Paper() : Tool("Paper") { }

int Paper::fight(Tool *other) {
  if (other->getType() == "Rock")
    return 1;
  else if (other->getType() == "Paper")
    return 0;
  else if (other->getType() == "Scissors")
    return 2;
  else
    return -1;
}
