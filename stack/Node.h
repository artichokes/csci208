#ifndef _Node_h
#define _Node_h

#include <stddef.h>
#include <cstddef>

template<class datumType>
class Node {
 private:
  datumType datum;
  Node *next;
 public:
  // Constructors
  Node();
  Node(datumType V);
  Node(datumType V, Node *n);

  // Set methods
  void setItem(datumType v);
  void setNext(Node *n);

  // Get Methods
  Node<datumType> *getNext();
  datumType getItem();
};
// create all constructors
template<class datumType>
Node<datumType>::Node() {
  next = NULL;
}

template<class datumType>
Node<datumType>::Node(datumType anItem) {
  datum = anItem;
  next = NULL;
}

template<class datumType>
Node<datumType>::Node(datumType anItem, Node<datumType> *nextNodePTR) {
  datum = anItem;
  next = nextNodePTR;
}

// Set methods
template<class datumType>
void Node<datumType>::setItem(datumType anItem) {
  datum = anItem;
}

template<class datumType>
void Node<datumType>::setNext(Node<datumType> *nextNodePTR) {
  next = nextNodePTR;
}

// Get methods
template<class datumType>
datumType Node<datumType>::getItem() {
  return datum;
}

template<class datumType>
Node<datumType> *Node<datumType>::getNext() {
  return next;
}


#endif
//end line?