#include <array>
#include <random>
#include <chrono>
#include <algorithm>
#include "Deck.h"

Deck::Deck() {
  // Fill the array with nullptr's
  this->card.fill(nullptr);

  // Fill the array with pointers to card
  for (size_t suit = 1; suit <= 4; suit++)
    for (size_t rank = 1; rank <= 13; rank++)
      this->card[13 * (suit - 1) + (rank - 1)] = new Card(static_cast<Rank>(rank), static_cast<Suit>(suit));
}

Deck::~Deck() {
  for (size_t suit = 1; suit <= 4; suit++) {
    for (size_t rank = 1; rank <= 13; rank++) {
      delete card[13 * (suit - 1) + (rank - 1)];
      card[13 * (suit - 1) + (rank - 1)] = nullptr;
    }
  }
}

Card *Deck::pick() {
  // Returns the first available card
  for (size_t i = 0; i < 52; i++)
    if (this->card[i] != nullptr)
      return pick(i);

  return nullptr;
}

Card *Deck::pick_random() {
  size_t index = this->distribution(this->generator);

  // If the card is available, pick the card
  if (this->card[index] != nullptr)
    return pick(index);

  // Search from the index until the end of the deck
  for (size_t i = index + 1; i < 52; i++)
    if (this->card[i] != nullptr)
      return pick(i);

  // Search from the start of the deck until the index
  for (size_t i = 0; i < index; i++)
    if (this->card[i] != nullptr)
      return pick(i);

  // If all pointers are nullptr (no card in deck), return nullptr
  return nullptr;
}

void Deck::shuffle() {
  long seed = std::chrono::system_clock::now().time_since_epoch().count();
  this->generator = std::default_random_engine(seed);
  std::shuffle(this->card.begin(), this->card.end(), this->generator);
}

Card *Deck::pick(size_t index) {
  if (index >= 52)
    return nullptr;

  Card *card_ptr = this->card[index];
  this->card[index] = nullptr;
  return card_ptr;
}
