#ifndef NODE_H
#define NODE_H

#include <stddef.h>
#include <cstddef>

using namespace std;

/******************************************************************
 Class Node
 Function: This object defines a node in a linked list or stack
     data structure
*******************************************************************/
template<class itemType>
class Node {
 private:
  itemType item;
  Node *next;
  bool isEmpty;
 public:
  /******************************************************************
   Class Node
   Function: Default Constructor
       Create an empty node object.
             Since this is a templated class, we cannot know what
             a null item will look like.
     Result: The next pointer is set to null.
             The flag: isEmpty is set to indicate that no item has been set.
     Return: a pointer to the constructed Node object.
  *******************************************************************/
  Node();

  /******************************************************************
   Class Node
   Function:  Constructor
       Create node object that has the data passed and is not linked
   Parameters: anItem is the data to add to the node object
   Result: The next pointer is set to null.
           The flag: isEmpty is set to indicate this node has data.
   Return: a pointer to the constructed Node object.
  *******************************************************************/
  Node(itemType V);

  /******************************************************************
   Class Node
   Function:  Constructor
       Create node object with the data passed and link the node
         to the next node with the pointer to a node.
   Parameters: anItem is the data to add to the node object
   Result: The next pointer is set to parameter passed.
              The flag: isEmpty is set to indicate this node has data.
   Return: a pointer to the constructed Node object.
  *******************************************************************/
  Node(itemType V, Node *n);

  /******************************************************************
   Class Node
   Function:  setItem
       Set the item variable with input parameter
   Parameters: anItem to set in the node object
   Result: The next pointer is not changed.
           The item value is changed.
           The flag: isEmpty is set/reset to indicate this node has data.
   Return: void
  *******************************************************************/
  void setItem(itemType v);

  /******************************************************************
   Class Node
   Function:  setNext
       Set the pointer to the next node
   Parameters: pointer to another node object
   Result: The next pointer is set to the pointer in the parameter
           The item value is not changed.
           The flag: isEmpty is not changed.
   Return: void
  *******************************************************************/
  void setNext(Node<itemType> *n);

  /******************************************************************
   Class Node
   Function:  getItem
       Return the value in the item variable
   Parameters: None
   Result: Nothing is changed, the item is returned
   Exception: If the item is not set, throw exception 9000 - Node not set
   Return: void
  *******************************************************************/
  itemType getItem();

  /******************************************************************
   Class Node
   Function:  getNext
       Return the pointer stored in this object
   Parameters: none
   Result: The next pointer is returned
   Return: valid Node object pointer or NULL
  *******************************************************************/
  Node *getNext();

  //EXCEPTIONS THROWN
  static const int NodeNotSet = 9000;

};

template<class itemType>
Node<itemType>::Node() {
  next = NULL;
  isEmpty = true;
}

template<class itemType>
Node<itemType>::Node(itemType anItem) {
  item = anItem;
  next = NULL;
  isEmpty = false;
}

template<class itemType>
Node<itemType>::Node(itemType anItem, Node<itemType> *nextNodePTR) {
  item = anItem;
  next = nextNodePTR;
  isEmpty = false;
}

template<class itemType>
void Node<itemType>::setItem(itemType anItem) {
  item = anItem;
  isEmpty = false;
}

template<class itemType>
void Node<itemType>::setNext(Node<itemType> *nextNodePTR) {
  next = nextNodePTR;
}

template<class itemType>
itemType Node<itemType>::getItem() {
  if (isEmpty) { throw NodeNotSet; }
  return item;
}


template<class itemType>
Node<itemType> *Node<itemType>::getNext() {
  return next;
}

#endif
 