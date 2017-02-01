#include "RPS.h"

#include <iostream>
#include <stdexcept>

RPS::RPS() {
  Tool *player = this->playerTurn();
  Tool *computer = this->computerTurn();
  std::cout << std::endl;

  std::cout << "\e[1;33mThe Player Chose:\t\e[0m" << *player << std::endl;
  std::cout << "\e[1;33mThe Computer Chose:\t\e[0m" << *computer << std::endl;
  std::cout << std::endl;

  switch (player->fight(computer)) {
    case -1:
      throw new std::range_error("The tools cannot fight each other!");
    case 0:
      std::cout << "\e[1;31mIt's a tie!\e[0m" << std::endl;
      break;
    case 1:
      std::cout << "\e[1;31mPlayer wins!\e[0m" << std::endl;
      break;
    case 2:
      std::cout << "\e[1;31mComputer wins!\e[0m" << std::endl;
      break;
    default:
      throw new std::range_error("Invalid result!");
  }

  delete player;
  delete computer;
}

Tool *RPS::playerTurn() {
  char input;

  while (true) {
    std::cout << "Rock, Paper, or Scissors (R,P,S)? ";
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Please enter R, P, or S." << std::endl;
    } else {
      input = static_cast<char>(tolower(input));

      switch (input) {
        case 'r':
          return new Rock();
        case 'p':
          return new Paper();
        case 's':
          return new Scissors();
        default:
          std::cout << "Please enter R, P, or S." << std::endl;
      }
    }
  }
}

Tool *RPS::computerTurn() {
  int tool = (std::rand() % 3) + 1;

  switch (tool) {
    case 1:
      return new Rock();
    case 2:
      return new Paper();
    case 3:
      return new Scissors();
    default:
      throw new std::range_error("The computer has gone rogue!");
  }
}
