#include <iostream>
#include "War.h"
#include "BlackJack.h"

using namespace std;

// Displays the menu
void menu();
// Picks a random card
void pick_random();

int main() {
  menu();
}

void menu() {
  War war = War();
  BlackJack blackJack = BlackJack();

  bool valid = false, quit = false;
  int input = 0;
  while (!valid || !quit) {
    // Prompt user for input
    cout << "1 - Pick a Random Card" << endl;
    cout << "2 - Play a Game of War" << endl;
    cout << "3 - Play a Game of BlackJack" << endl;
    cout << "4 - Quit" << endl;
    cout << endl;
    cout << "Pick a choice (1-4): " << endl;
    cin >> input;

    // Check if input is valid
    if (cin.fail() || input < 1 || input > 4) {
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
          cout << endl;
          break;
        case 2:
          cout << endl;
          war.play();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 3:
          cout << endl;
          blackJack.play();
          cout << "\n\e[1;97mPress Enter to continue...\e[0m\n";
          cin.ignore();
          cin.get();
          break;
        case 4: quit = true; break;
        default: valid = false; break;
      }
    }
  }
}

void pick_random() {
  std::cout << "\e[1;33mRandom Card:\e[0m " << *Deck().pick_random() << std::endl;
};
