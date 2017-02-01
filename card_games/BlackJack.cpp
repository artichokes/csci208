#include "BlackJack.h"

void BlackJack::play() {
  this->deck = new Deck();
  this->deck->shuffle();

  initial_deal();
  std::cout << std::endl;
  player_turn();
  std::cout << std::endl;
  house_turn();
  std::cout << std::endl;
  winner();

  delete this->deck;
  this->deck = nullptr;
  this->house_hand = 0;
  this->player_hand = 0;
}

size_t BlackJack::cardToPoints(const Card &card) {
  switch (card.getRank()) {
    case Rank::Joker: return 0;
    case Rank::Ace: return 1;
    case Rank::Two: return 2;
    case Rank::Three: return 3;
    case Rank::Four: return 4;
    case Rank::Five: return 5;
    case Rank::Six: return 6;
    case Rank::Seven: return 7;
    case Rank::Eight: return 8;
    case Rank::Nine: return 9;
    case Rank::Ten: return 10;
    case Rank::Jack: return 10;
    case Rank::Queen: return 10;
    case Rank::King: return 10;
  }
}

void BlackJack::initial_deal() {
  Card *house1 = this->deck->pick(), *house2 = this->deck->pick();   // House cards
  this->house_hand += cardToPoints(*house1);
  this->house_hand += cardToPoints(*house2);
  Card *player1 = this->deck->pick(), *player2 = this->deck->pick(); // Player cards
  this->player_hand += cardToPoints(*player1);
  this->player_hand += cardToPoints(*player2);

  std::cout << "                     \e[1;33mHouse:\e[0m" << std::endl;
  std::cout << "House cards: " << *house1 << " and "  << *house2 << std::endl;
  std::cout << "Total: " << this->house_hand << std::endl;
  std::cout << std::endl;

  std::cout << "                    \e[1;33mPlayer:\e[0m" << std::endl;
  std::cout << "Player cards: " << *player1 << " and "  << *player2 << std::endl;
  std::cout << "Total: " << this->player_hand << std::endl;
}

void BlackJack::player_turn() {
  std::cout << "                  \e[1;33mPlayer Turn:\e[0m" << std::endl;

  bool valid = false, hit = true;
  int input = 0;
  while (!valid || hit) {
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "Would you like to hit? ";
    std::cin >> input;

    // Check if input is valid
    if (std::cin.fail() || input < 1 || input > 2) {
      std::cout << std::endl;
      std::cout << "Invalid choice!" << std::endl;
      std::cout << std::endl;
      std::cin.clear();
      std::cin.ignore();
      valid = false;
    } else {
      valid = true;
    }

    // If input is valid, convert input to bool
    if (valid) {
      if (input == 1) { // If player hits
        hit = true;

        Card *card = this->deck->pick();
        if (card == nullptr)
          throw "No more cards!";
        else
          this->player_hand += cardToPoints(*card);

        std::cout << std::endl;
        std::cout << "                    \e[1;33mPlayer:\e[0m" << std::endl;
        std::cout << "New card: " << *card << std::endl;
        std::cout << "Total: " << this->player_hand << std::endl;
        std::cout << std::endl;
      } else if (input == 2)
        hit = false;
    }
  }
}

void BlackJack::house_turn() {
  while ((this->house_hand < this->player_hand) && (this->house_hand < 21) && (this->player_hand < 21)) {
    Card *card = this->deck->pick();
    if (card == nullptr)
      throw "No more cards!";
    else
      this->house_hand += cardToPoints(*card);

    std::cout << std::endl;
    std::cout << "                     \e[1;33mHouse:\e[0m" << std::endl;
    std::cout << "New card: " << *card << std::endl;
    std::cout << "Total: " << this->house_hand << std::endl;
    std::cout << std::endl;
  }
}

void BlackJack::winner() {
  std::cout << "                    \e[1;33mResults:\e[0m" << std::endl;
  std::cout << "Player: " << this->player_hand << "\t";
  std::cout << "House: " << this->house_hand << std::endl;
  std::cout << std::endl;

  if ((this->player_hand == 21) ||
      ((this->player_hand < 21) && (this->house_hand > 21)))
    std::cout << "\e[1;31mWinner: Player!\e[0m" << std::endl;
  else
    std::cout << "\e[1;31mWinner: House!\e[0m" << std::endl;
}
