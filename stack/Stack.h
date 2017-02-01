//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Updates by Marguerite Doman 2014

/** @file StackInterface.h */

#ifndef _STACK_H
#define _STACK_H

#include "Node.h"


template<class ItemType>
class Stack {

 private:
  Node<ItemType> *topOfStackPtr;
 public:

  /*****************************************************
   METHOD:  Constructor
   ****************************************************/
  Stack() : topOfStackPtr(NULL) { }

  /*****************************************************
   METHOD:  isEMPTY
       Sees whether this stack is empty.
   RETURNS: True if the stack is empty, or false if not.
   ****************************************************/
  bool isEmpty() { return topOfStackPtr == NULL; }

  /*****************************************************
   METHOD:  PUSH
       Adds a new entry to the top of this stack.
       If the operation was successful,
                  newEntry is at the top of the stack.

   PARAMETER: newEntry The object to be added as a new entry.
   RETURNS: True if the addition is successful or false if not.
  ****************************************************/
  bool push(ItemType newEntry) {
    topOfStackPtr = new Node<ItemType>(newEntry, topOfStackPtr);
    return true;
  }


  /*****************************************************
   METHOD:  POP
       Removes the top of this stack.
       If the operation was successful,
             the top of the stack has been removed.

   PARAMETER: None
   RETURNS: The item removed from the stack
   ERROR RETURNED:  If the stack is empty an error is returned
           student: define the error you will return here
   ****************************************************/
  ItemType pop() {
    if (topOfStackPtr == NULL)
      throw StackEmpty;

    Node<ItemType> *nodePtr = topOfStackPtr;
    topOfStackPtr = nodePtr->getNext();
    return nodePtr->getItem();
  }

  static const int StackEmpty = 1000;
};

#endif // end Stack.h
