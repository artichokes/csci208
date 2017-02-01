#include "War.h"

void War::play(unsigned rounds) {
  this->deck = new Deck();
  this->deck->shuffle();

  // Play rounds until the numbers of rounds or until out of cards
  for (; (this->round <= rounds) && (play_round() != -1); this->round++)
    std::cout << std::endl;

  print_results();

  delete this->deck;
  this->deck = nullptr;
  this->round = 1;
  this->player1_score = 0;
  this->player2_score = 0;
}

int War::play_round() {
  // Pick the player cards
  Card *player1 = deck->pick();
  Card *player2 = deck->pick();

  if (player1 == nullptr || player2 == nullptr)
    return -1;

  std::cout << "          \e[1;33mRound " << this->round << ":\e[0m" << std::endl;
  std::cout << "Player 1 drew " << *player1 << "!" << std::endl;
  std::cout << "Player 2 drew " << *player2 << "!" << std::endl;
  std::cout << std::endl;
  if (*player1 > *player2) {
    std::cout << "\e[91mPlayer 1 wins the round!\e[0m" << std::endl << std::endl;
    this->player1_score++;
    print_score();
    return 1;
  } else if (*player2 > *player1) {
    std::cout << "\e[91mPlayer 2 wins the round!\e[0m" << std::endl << std::endl;
    this->player2_score++;
    print_score();
    return 2;
  } else {
    std::cout << "\e[91mIt's a tie round!\e[0m" << std::endl << std::endl;
    print_score();
    return 0;
  }
}

void War::print_score() {
  std::cout << "          \e[1mScore:\e[0m" << std::endl;
  std::cout << "Player 1: " << this->player1_score << "\t";
  std::cout << "Player 2: " << this->player2_score << std::endl;
}

void War::print_results() {
  std::cout << "         \e[1;33mResults:\e[0m" << std::endl;
  std::cout << "Player 1: " << this->player1_score << "\t";
  std::cout << "Player 2: " << this->player2_score << std::endl;
  std::cout << std::endl;

  if (player1_score > player2_score)
    std::cout << "\e[1;31mWinner: Player 1!\e[0m" << std::endl;
  else if (player2_score > player1_score)
    std::cout << "\e[1;31mWinner: Player 2!\e[0m" << std::endl;
  else
    std::cout << "\e[1;31mIt's a tie!\e[0m" << std::endl;
}
