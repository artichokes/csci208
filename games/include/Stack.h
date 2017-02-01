#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template<class itemType>
class Stack : protected LinkedList<itemType> {
 public:
  void push(itemType element) { this->insertFront(element); }
  itemType pop() { return this->retrieveAtPos(0); }
  itemType peak() { return this->findPos(0); }
};

#endif //STACK_H
