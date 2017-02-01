#include<iostream>
#include <cstdlib>
#include <cstddef>
#include "LinkedList.h"


int readInt(string);
int main() {

  char choice;
  int item;
  LinkedList a;

  cout << "This program demonstrates the linked list. " << endl;
  cout << "Initially, you will be asked to create the list." << endl;
  cout << "You will be later prompted to manipulate the list." << endl << endl;


  choice = 'b';


  cout << "*******************************************************" << endl;
  cout << "1: InsertFront(Insert an element at the beginning of the list)\n";
  cout << "2: InsertRear (Append an element to the end of the list)\n";
  cout << "3: isEmpty (Indicate whether the list is empty)\n";
  cout << "4: count (Count the number of items in the list)\n";
  cout << "5: Print  (Print the content of the current list)\n";
  cout << "6: Find (Find the position of a node with a given value)\n";
  cout << "7: Retrieve at position (Return and delete a node at a given position)\n";
  cout << "8: Clear (Clears or empties the list\n";
  cout << "9: Quit   (Quit the program)\n";
  cout << "\n10: (Extra Credit) InsertInOrder (Add an element to a sorted list)\n";
  cout << "*******************************************************" << endl << endl;
  while (choice != '9') {
    cout << "\n   Please enter your choice here:  ";
    cin >> choice;

    switch (choice) {
      case '1':
        item = readInt("to insert at the front of the list:  ");
        a.insertFront(item);
        break;

      case '2':
        item = readInt("to append to the end:  ");
        a.insertRear(item);
        break;

      case '3':
        if (a.isEmpty()) { cout << "The list is empty" << endl; }
        else { cout << "The list is NOT empty" << endl; }
        cout << endl << endl;
        break;

      case '4': {
        cout << "The list has " << a.count() << " items" << endl;
      }
        break;

      case '5':
        cout << "The content of the current ordered list is:  " << endl;
        a.printList();
        cout << endl << endl;
        break;

      case '6':
        item = readInt("to find the position of element:  ");
        try {
          cout << "\n Item found at position " << a.findPos(item) << endl;
        } catch (int exception) {
          if (exception == LinkedList::ItemNotFound) { cout << " Item not found" << endl; }
          else { throw exception; }// Not the one we are looking for... rethrow it
        }
        cout << endl << endl;
        break;

      case '7':
        item = readInt("for position to remove:  ");
        try {
          cout << "Item removed is: " << a.retrieveAtPos(item) << endl;
        } catch (int exception) {
          if (exception == LinkedList::NodeAtPositionNotFound) { cout << " Node not found" << endl; }
          else { throw exception; }// Not the one we are looking for... rethrow it
        }
        cout << endl << endl;
        break;

      case '8':
        a.clear();
        break;

      case '9':
        break;

      default:
        cout << "\n Invalid choice. Please try again.\n";
        break;
    }
  }
  cout << "\n Bye\n";
  return 0;
}
int readInt(string descr) {
  int item;
  cout << "\n   Please enter an integer value " << descr;
  cin >> item;

  while (cin.fail()) // no extraction took place
  {
    cout << "\n Please try again:";
    cin.clear(); // reset the state bits back to goodbit so we can use ignore()
    cin.ignore(1000, '\n'); // clear out the bad input from the stream
    cin >> item;
  }

  while (item < 0) {
    cout << "\n Please try again:";
    cin >> item;
  }
  return item;
}
