#ifndef HAND_H
#define HAND_H

#include <stdexcept>
#include "LinkedList.h"
#include "Card.h"

class Hand: protected LinkedList<Card> {
 public:
  Hand();

  // Adds a card to the hand if possible
  void addCard(Card card);

  // Removes a card from the hand at the specified position
  // @param pos index to remove card (starts at 0)
  // @return The card
  // @throws CardOutOfRangeException if cannot find card
  Card removeCard(int pos);

  // Select a card from the hand at the specified position
  // without removing the card
  // @param pos index to remove card (starts at 0)
  // @return The card
  // @throws CardOutOfRangeException if cannot find card
  Card selectCard(int pos) const;

  // Checks if hand is empty
  // @return True if hand is empty
  bool isEmpty();

  // Searches the hand for an eight
  // @returns The position of the card or -1 if non found
  int searchEight();

  // Searches the hand for the suit
  // @returns The position of the card or -1 if non found
  int searchSuit(Suit suit);

  // Searches the hand for the rank
  // @returns The position of the card or -1 if non found
  int searchRank(Rank rank);

  // Prints the cards in the hand
  void showCards();

  class CardOutOfRangeException;
};

class Hand::CardOutOfRangeException: public runtime_error {
 public:
  CardOutOfRangeException() : runtime_error("Card index out of range") { }
};

#endif //HAND_H
