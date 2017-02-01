/* Filename:  reverse.cpp

   Programmer:  Br. David Carlson

   Date:  March 28, 1998

   Last Modified:  March 14, 2014

   This program prompts the user to enter a sequence of numbers (floats)
   and then prints them in reverse order.  (Change the CTRL z to CTRL d
   for Linux.)

   Tested with:
      Microsoft Visual Studio 2008
      Microsoft Visual Studio 2010
      g++ in Linux
*/
#include <iostream>

#include "Stack.h"

using namespace std;


int main(void) {
  Stack<int> StackSequence;
  int Number, Item;

  // Change CTRL z to CTRL d for Linux:
  cout << "Enter a number (CTRL d to end): ";
  cin >> Number;

  while (!cin.fail()) {
    StackSequence.push(Number);
    // Change CTRL z to CTRL d for Linux:
    cout << "Enter another number (CTRL d to end): ";
    cin >> Number;
  }

  if (StackSequence.isEmpty())
    cout << endl << endl << "Stack is empty" << endl;
  else {
    cout << endl << endl << "Numbers in reverse order are:" << endl;
    while (!StackSequence.isEmpty()) {
      Item = StackSequence.pop();
      cout << Item << endl;
    }
  }

  return 0;
}

