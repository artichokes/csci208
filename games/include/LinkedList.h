#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Node.h"

using namespace std;

/******************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************/
template<class itemType>
class LinkedList {
 private:
  void recursive_delete(Node<itemType> *nodePtr);

 protected:
  Node<itemType> *headNodePtr;

 public:
  /******************************************************************
   Class LinkedList
   Function:  Constructor
       Create am empty linked list
       This is indicated by a null pointer in the start of list (headNodePtr)
   Return: a pointer to the constructed LinkedList object.
  *******************************************************************/
  LinkedList();

  /******************************************************************
  Class LinkedList
  Function:  isEmpty
  Parameters: None
   Returns a bool that indicates if the linked list is or is not empty
  *******************************************************************/
  bool isEmpty() const;

  /******************************************************************
   Class LinkedList
   Function:  insertFront
       Inserts a new item at the front of the list
       This routing will create a Node object to contain the item to add
   Parameters: item to add to the list
   Return: void
  *******************************************************************/
  void insertFront(itemType item);

  /******************************************************************
   Class LinkedList
   Function:  insertRear
       Inserts a new item at the end of the list
       This routing will create a Node object to contain the item to add
   Parameters: item to add to the list
   Return: void
  *******************************************************************/
  void insertRear(itemType item);

  /******************************************************************
  Class LinkedList
  Function:  count
  Parameters: None
   Returns an integer count of the number of items in the list
  *******************************************************************/
  int count();

  /******************************************************************
   Class LinkedList
   Function:  printList
      Prints the contents of the linked list delimited by commas

   Result:  NPrints the list.
  *******************************************************************/
  void printList();

  /******************************************************************
   Class LinkedList
   Function:  findPos
      Walks through the list looking for a node at the position passed.
      The position starts counting at 0. That is the first node in the list
      is at position 0.
      If that node is found, it returns the position of that node in the list.

      If the node is not found, signal an  exception: itemNotFound

   Parameters: Position in list.

   Return: item at that position
  *******************************************************************/
  itemType findPos(int pos) const;

  /******************************************************************
   Class LinkedList
   Function:  retrieveAtPos
      Walks through the list looking for a node at the position passed.
      The position starts counting at 0. That is the first node in the list
      is at position 0.
      If that node is found, it removes the node from the list
       and returns the value.

       If the node is not found, signal an  exception: NodeAtPositionNotFound

   Parameters: Position in list.

   Result:  Node with item is removed from the list.
   Return: item at that position
  *******************************************************************/
  itemType retrieveAtPos(int pos);

  /******************************************************************
  Class LinkedList
  Function:  clear
  Parameters: None1
   Removes and deletes all the entries of the list
    Function:  isEmpty
   Returns void
  *******************************************************************/
  void clear();

  // EXCEPTIONS THROWN
  class ItemNotFoundException;
  class NodeAtPositionNotFoundException;
};

template<class itemType>
LinkedList<itemType>::LinkedList() {
  headNodePtr = nullptr;
}

template<class itemType>
bool LinkedList<itemType>::isEmpty() const {
  return headNodePtr == nullptr;
}

template<class itemType>
void LinkedList<itemType>::insertFront(itemType item) {
  // The headNodePtr currently points to the first node in the list or nullptr
  // Create the new node with the item given and point it to the same node (or nullptr) as the head

  Node<itemType> *newNodePtr = new Node<itemType>(item, this->headNodePtr);

  // Set the head node pointer equal to the new node, now the first one in the list
  this->headNodePtr = newNodePtr;

  // Now the head node points to the new node and the new node points to the rest of the list.
}

template<class itemType>
void LinkedList<itemType>::insertRear(itemType item) {
  Node<itemType> *nodePtr = headNodePtr;

  while (nodePtr->getNext() != nullptr)
    nodePtr = nodePtr->getNext();

  Node<itemType> *newNodePtr = new Node<itemType>(item);
  nodePtr->setNext(newNodePtr);
}

template<class itemType>
int LinkedList<itemType>::count() {
  int count = 0;

  for (Node<itemType> *nodePtr = headNodePtr;
       nodePtr != nullptr;
       nodePtr = nodePtr->getNext())
    ++count;

  return count;
}

template<class itemType>
void LinkedList<itemType>::printList() {
  ostringstream buffer;

  for (Node<itemType> *nodePtr = headNodePtr;
       nodePtr != nullptr;
       nodePtr = nodePtr->getNext()) {
    buffer << nodePtr->getItem();

    if (nodePtr->getNext() != nullptr)
      buffer << ", ";
  }

  cout << buffer.str() << endl;
}

template<class itemType>
itemType LinkedList<itemType>::findPos(int pos) const {
  int item = 0;
  Node<itemType> *nodePtr = headNodePtr;

  while (nodePtr != nullptr && item != pos) {
    nodePtr = nodePtr->getNext();
    ++item;
  }

  if (item == pos && nodePtr != nullptr)
    return nodePtr->getItem();
  else
    throw ItemNotFoundException();
}

template<class itemType>
itemType LinkedList<itemType>::retrieveAtPos(int pos) {
  int item = 0;
  Node<itemType> *prevPtr = this->headNodePtr;
  Node<itemType> *nodePtr = this->headNodePtr;
  itemType val;

  if (item == pos && this->headNodePtr != nullptr) {
    this->headNodePtr = this->headNodePtr->getNext();
    val = nodePtr->getItem();
    delete nodePtr;
    return val;
  }

  while (nodePtr != nullptr && item != pos) {
    prevPtr = nodePtr;
    nodePtr = nodePtr->getNext();
    ++item;
  }

  if (item == pos && nodePtr != nullptr) {
    prevPtr->setNext(nodePtr->getNext());
    val = nodePtr->getItem();
    delete nodePtr;
    return val;
  } else
    throw NodeAtPositionNotFoundException();
}

template<class itemType>
void LinkedList<itemType>::clear() {
  recursive_delete(this->headNodePtr);
  this->headNodePtr = nullptr;
}

template<class itemType>
void LinkedList<itemType>::recursive_delete(Node<itemType> *nodePtr) {
  if (nodePtr != nullptr) {
    recursive_delete(nodePtr->getNext());
    delete nodePtr;
  }
}

template<class itemType>
class LinkedList<itemType>::ItemNotFoundException: public runtime_error {
 public:
  ItemNotFoundException() : runtime_error("Item not found") { }
};

template<class itemType>
class LinkedList<itemType>::NodeAtPositionNotFoundException: public runtime_error {
 public:
  NodeAtPositionNotFoundException() : runtime_error("Node at position not found") { }
};

#endif
