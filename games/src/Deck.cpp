#include <array>
#include <ctime>
#include <cstdlib>
#include "Deck.h"


Deck::Deck() {
  // Fill with the cards
  for (size_t suit = 1; suit <= 4; suit++)
    for (size_t rank = 1; rank <= 13; rank++)
      this->push(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
}

Card Deck::draw() {
  try {
    return this->pop();
  } catch (NodeAtPositionNotFoundException) {
    throw DeckEmptyException();
  }
}

void Deck::shuffle() {
  for (size_t i = 0; i < 10; ++i) {
    int randomNum = (rand() % 8) + 1; // Pick a random number between 1 and 8.
    Stack<Card> deck1, deck2;

    // Divide the deck into 2 temporary stacks
    for (size_t j = 0; j < 22+randomNum; ++j)
      deck1.push(this->draw());

    for (size_t j = 0; j < 22+(8-randomNum); ++j)
      deck2.push(this->draw());

    // Merge the two temporary decks
    for (size_t j = 0; j < 22; ++j) {
      this->push(deck1.pop());
      this->push(deck2.pop());
    }

    if (randomNum < 4) { // Deck 1 is shorter
      for (size_t j = 0; j < randomNum; ++j) {
        this->push(deck1.pop());
        this->push(deck2.pop());
      }

      for (size_t j = 0; j < (8-randomNum-randomNum); ++j)
        this->push(deck2.pop());
    } else { // Deck 2 is shorter
      for (size_t j = 0; j < (8-randomNum); ++j) {
        this->push(deck1.pop());
        this->push(deck2.pop());
      }

      for (size_t j = 0; j < (randomNum+randomNum-8); ++j)
        this->push(deck1.pop());
    }
  }
}
