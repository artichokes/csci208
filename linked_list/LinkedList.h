// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Node.h"

using namespace std;

/******************************************************************
 Class LinkedList
 This class defines a data structure for a linked list of integers
*******************************************************************/
class LinkedList {
 private:
  Node<int> *headNodePtr;

 public:
  LinkedList();
  bool isEmpty();
  void insertFront(int);
  void insertRear(int);
  int count();
  void printList();
  int findPos(int);
  int retrieveAtPos(int);
  void clear();


  // EXCEPTIONS THROWN
  static const int ItemNotFound = 8001;
  static const int NodeAtPositionNotFound = 8002;
};


/*=====================================================================
/*     IMPLEMENTATION OF METHOD/FUNCTIONS
/*=====================================================================

/******************************************************************
 Class LinkedList
 Function:  Constructor
     Create am empty linked list
	 This is indicated by a null pointer in the start of list (headNodePtr)
 Return: a pointer to the constructed LinkedList object.
*******************************************************************/
LinkedList::LinkedList() {
  headNodePtr = NULL;
}

/******************************************************************
Class LinkedList
Function:  isEmpty
Parameters: None
 Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/
bool LinkedList::isEmpty() {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  // Print each item on a new line
  return headNodePtr == NULL;
}

/******************************************************************
 Class LinkedList
 Function:  insertFront
     Inserts a new item at the front of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
void LinkedList::insertFront(int item) {
  // The headNodePtr currently points to the first node in the list or NULL
  // Create the new node with the item given and point it to the same node (or NULL) as the head

  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  Node<int> *newNodePtr = new Node<int>(item, this->headNodePtr);

  // Set the head node pointer equal to the new node, now the first one in the list
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  this->headNodePtr = newNodePtr;

  // Now the head node points to the new node and the new node points to the rest of the list.
}

/******************************************************************
 Class LinkedList
 Function:  insertRear
     Inserts a new item at the end of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
void LinkedList::insertRear(int item) {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  Node<int> *nodePtr = headNodePtr;

  while (nodePtr->getNext() != NULL)
    nodePtr = nodePtr->getNext();

  Node<int> *newNodePtr = new Node<int>(item);
  nodePtr->setNext(newNodePtr);
}

/******************************************************************
Class LinkedList
Function:  count
Parameters: None
 Returns an integer count of the number of items in the list
*******************************************************************/
int LinkedList::count() {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  // Print each item on a new line
  int count = 0;

  for (Node<int> *nodePtr = headNodePtr;
       nodePtr != NULL;
       nodePtr = nodePtr->getNext())
    ++count;

  return count;
}

/******************************************************************
 Class LinkedList
 Function:  printList
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list 
	 and returns the value.
	 
	 If the node is not found, signal an  exception: NodeAtPositionNotFound
	 
 Parameters: item to find.
 Result:  Node with item is removed from the list.
 Return: item
*******************************************************************/
void LinkedList::printList() {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  // Print each item on a new line
  ostringstream buffer;

  for (Node<int> *nodePtr = headNodePtr;
       nodePtr != NULL;
       nodePtr = nodePtr->getNext())
      buffer << nodePtr->getItem() << " ";

  cout << buffer.str() << endl;
}

/******************************************************************
 Class LinkedList
 Function:  findPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it returns the position of that node in the list.
	 
	If the node is not found, signal an  exception: itemNotFound
	 
 Parameters: Position in list.

 Return: item at that position
*******************************************************************/
int LinkedList::findPos(int item) {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  int pos = 0;
  Node<int> *nodePtr = headNodePtr;

  while (nodePtr != NULL && pos != item) {
    nodePtr = nodePtr->getNext();
    ++pos;
  }

  if (pos == item && nodePtr != NULL)
    return nodePtr->getItem();
  else
    throw ItemNotFound;
}

/******************************************************************
 Class LinkedList
 Function:  retrieveAtPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list 
	 and returns the value.
	 
	 If the node is not found, signal an  exception: NodeAtPositionNotFound
	 
 Parameters: Position in list.

 Result:  Node with item is removed from the list.
 Return: item at that position
*******************************************************************/
int LinkedList::retrieveAtPos(int pos) {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE

  if (headNodePtr == NULL)
    throw NodeAtPositionNotFound;

  int currentPos = 0;
  Node<int> *prevPtr = headNodePtr;
  Node<int> *nodePtr = prevPtr->getNext();

  while (nodePtr != NULL && currentPos != pos) {
    prevPtr = prevPtr->getNext();
    nodePtr = prevPtr->getNext();
    ++currentPos;
  }

  if (currentPos == pos && nodePtr != NULL) {
    prevPtr->setNext(nodePtr->getNext());
    return nodePtr->getItem();
  } else
    throw NodeAtPositionNotFound;
}


/******************************************************************
Class LinkedList
Function:  clear
Parameters: None
 Removes and deletes all the entries of the list
  Function:  isEmpty
 Returns void
*******************************************************************/
void LinkedList::clear() {
  //REPLACE THE LINE BELOW WITH YOUR OWN CODE
  // Print each item on a new line
  headNodePtr = NULL;
}

#endif
