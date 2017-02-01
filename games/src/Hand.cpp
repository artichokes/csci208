#include <iomanip>
#include "Hand.h"

Hand::Hand() : LinkedList() { }

void Hand::addCard(Card card) {
  insertFront(card);
}

Card Hand::removeCard(int pos) {
  try {
    return retrieveAtPos(pos);
  } catch (LinkedList::NodeAtPositionNotFoundException) {
    throw CardOutOfRangeException();
  }
}

Card Hand::selectCard(int pos) const {
  try {
    return findPos(pos);
  } catch (LinkedList::ItemNotFoundException) {
    throw CardOutOfRangeException();
  }
}

bool Hand::isEmpty() {
  return this->headNodePtr == nullptr;
}

int Hand::searchEight() {
  return searchRank(Rank::Eight);
}

int Hand::searchSuit(Suit suit) {
  int pos = 0;

  for (Node<Card> *nodePtr = this->headNodePtr; nodePtr != nullptr; nodePtr = nodePtr->getNext()) {
    if (nodePtr->getItem().getSuit() == suit)
      return pos;

    ++pos;
  }

  return -1;
}

int Hand::searchRank(Rank rank) {
  int pos = 0;

  for (Node<Card> *nodePtr = this->headNodePtr; nodePtr != nullptr; nodePtr = nodePtr->getNext()) {
    if (nodePtr->getItem().getRank() == rank)
      return pos;

    ++pos;
  }

  return -1;
}

void Hand::showCards() {
  cout << "|---|-------------------|---|-------------------|---|-------------------|" << endl;

  size_t i = 1;
  for (Node<Card> *nodePtr = this->headNodePtr; nodePtr != nullptr; nodePtr = nodePtr->getNext()) {
    cout << "| " << i << " | " << left << setw(17) << setfill(' ') << nodePtr->getItem() << ' ';
    if (i % 3 == 0) {
      cout << '|' << endl;
      cout << "|---|-------------------|---|-------------------|---|-------------------|" << endl;
    }
    ++i;
  }

  --i;
  while (i % 3 != 0) {
    cout << "|   |                   ";

    if ((i + 1) % 3 == 0) {
      cout << '|' << endl;
      cout << "|---|-------------------|---|-------------------|---|-------------------|" << endl;
    }

    ++i;
  }
}
