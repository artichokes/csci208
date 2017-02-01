#include "MagicCard.h"

MagicCard::MagicCard() : deck(Deck()) {
  this->deck.shuffle();

  this->card = this->deck.draw();
  std::cout << "\e[1;33mYour Card: \e[0m" << card << std::endl;
  std::cout << std::endl;

  convertCardToQueenOfHearts(card);
  std::cout << "\e[1;31m** Poof! **\e[0m" << std::endl;
  std::cout << std::endl;

  std::cout << "\e[1;33mYour Card: \e[0m" << card << std::endl;
}

void MagicCard::convertCardToQueenOfHearts(Card &card) {
  card.setRank(Rank::Queen);
  card.setSuit(Suit::Hearts);
}