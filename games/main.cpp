#include <cstdlib>
#include <ctime>
#include <iostream>
#include "War.h"
#include "BlackJack.h"
#include "MagicCard.h"
#include "RPS.h"
#include "CrazyEights.h"

using namespace std;

// Displays the menu
void menu();
// Picks a random card
void pick_random();

int main() {
  srand(time(nullptr));
  menu();
}

void menu() {
  bool valid = false, quit = false;
  int input = 0;
  while (!valid || !quit) {
    // Prompt user for input
    cout << "1 - Pick a Random Card" << endl;
    cout << "2 - Play a Game of War" << endl;
    cout << "3 - Play a Game of BlackJack" << endl;
    cout << "4 - Pick a Magic Card" << endl;
    cout << "5 - Play Rock-Paper-Scissors" << endl;
    cout << "6 - Play Crazy Eights" << endl;
    cout << "7 - Quit" << endl;
    cout << endl;
    cout << "Pick a choice (1-7): ";
    cin >> input;

    // Check if input is valid
    if (cin.fail() || input < 1 || input > 7) {
      cin.clear();
      cin.ignore();
      valid = false;
      cout << "\nInvalid option!\n\n";
    } else {
      valid = true;

      // If input is valid, do actions
      switch (input) {
        case 1:
          cout << endl;
          pick_random();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 2:
          cout << endl;
          War();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.get();
          break;
        case 3:
          cout << endl;
          BlackJack();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 4:
          cout << endl;
          MagicCard();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 5:
          cout << endl;
          RPS();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 6:
          cout << endl;
          CrazyEights();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 7: quit = true; break;
        default: valid = false; break;
      }
    }
  }
}

void pick_random() {
  Deck deck;
  deck.shuffle();
  std::cout << "\e[1;33mRandom Card:\e[0m " << deck.draw() << std::endl;
};
