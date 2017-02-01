#include "CrazyEights.h"

CrazyEights::CrazyEights() :
    deck(Deck()),
    discardPile(DiscardPile()),
    player(Hand()),
    computer(Hand()) {

  deck.shuffle();
  dealCards();
  discardPile.push(deck.draw());
  discardPile.setSuit(discardPile.peak().getSuit());

  playerTurn();
}

void CrazyEights::dealCards() {
  for (size_t i = 0; i < 8; i++) {
    this->player.addCard(this->deck.draw());
    this->computer.addCard(this->deck.draw());
  }
}

void CrazyEights::showLastDiscarded() {
  cout << "\e[1;33mCurrent card: \e[0m" << discardPile.peak() << endl;
  if (discardPile.peak().getRank() == Rank::Eight) {
    cout << "\e[1;33mCrazy Eight Suit: \e[0m" << discardPile.getSuit() << endl;
  }
}

void CrazyEights::showPlayerHand() {
  cout << "\e[1;33mPlayer cards: \e[0m" << endl;
  player.showCards();
}

void CrazyEights::showComputerHand() {
  cout << "\e[1;33mComputer cards: \e[0m" << endl;
  computer.showCards();
}

void CrazyEights::playerTurn() {
  bool valid = false;
  int input;
  Card choice;

  showLastDiscarded();
  cout << endl;

  showPlayerHand();
  cout << endl;

  // If an eight was played
  if (discardPile.peak().getRank() == Rank::Eight) {
    // The player must play the crazy eight suit or another eight
    if ((player.searchSuit(discardPile.getSuit()) == -1) && // If not possible draw a card
        (player.searchEight() == -1)) {
      cout << "\n\e[1;97mPress Enter to draw a card...\e[0m\n";
      cin.get();
      cin.ignore();

      try {
        player.addCard(deck.draw());
      } catch (Deck::DeckEmptyException) { // If there are no more cards compare scores
        compareScores();
      }
    } else {
      valid = false;
      while (!valid) {
        cout << "Choose a card: ";
        cin >> input;

        if (cin.fail()) {
          valid = false;
          cin.clear();
          cin.ignore();
          cout << "Invalid input!" << endl;
          continue;
        }

        try {
          choice = player.removeCard(input - 1);
        } catch (Hand::CardOutOfRangeException) {
          valid = false;
          cout << "Please select a valid card!" << endl;
          continue;
        }

        if ((choice.getSuit() != discardPile.getSuit()) && (choice.getRank() != Rank::Eight)) {
          valid = false;
          player.addCard(choice);
          cout << "The suit must match the crazy eight suit or must be an eight." << endl;
          continue;
        } else {
          valid = true;
          discardPile.push(choice);
          cout << endl;
        }

        if (choice.getRank() == Rank::Eight)
          chooseSuit();
      }
    }
  } else { // If no eight was played
    // The player must play a matching suit, matching rank, or an eight
    if ((player.searchSuit(discardPile.peak().getSuit()) == -1) && // If not possible draw a card
        (player.searchRank(discardPile.peak().getRank()) == -1) &&
        (player.searchEight() == -1)) {
      cout << "\n\e[1;97mPress Enter to draw a card...\e[0m\n";
      cin.get();
      cin.ignore();

      try {
        player.addCard(deck.draw());
      } catch (Deck::DeckEmptyException) { // If there are no more cards compare scores
        compareScores();
      }
    } else {
      valid = false;
      while (!valid) {
        cout << "Choose a card: ";
        cin >> input;

        if (cin.fail()) {
          valid = false;
          cin.clear();
          cin.ignore();
          cout << "Invalid input!" << endl;
          continue;
        }

        try {
          choice = player.removeCard(input - 1);
        } catch (Hand::CardOutOfRangeException) {
          valid = false;
          cout << "Please select a valid card!" << endl;
          continue;
        }

        if ((choice.getSuit() != discardPile.peak().getSuit())
            && (choice.getRank() != Rank::Eight)
            && (choice.getRank() != discardPile.peak().getRank())) {
          valid = false;
          player.addCard(choice);
          cout << "The suit must match the previously played card's suit or rank, or must be an eight." << endl;
          continue;
        } else {
          valid = true;
          discardPile.push(choice);
          cout << endl;
        }

        if (choice.getRank() == Rank::Eight)
          chooseSuit();
      }
    }
  }

  if (player.isEmpty())
    playerWins();
  else
    computerTurn();
}

void CrazyEights::chooseSuit() {
  bool valid = false;
  int input;

  while (!valid) {
    cout << "\e[1;97m1 = Clubs, 2 = Diamonds, 3 = Hearts, 4 = Spades\e[0m" << endl;
    cout << "Choose a suit: ";
    cin >> input;

    if (cin.fail()) {
      valid = false;
      cin.clear();
      cin.ignore();
      cout << "Invalid input!";
      continue;
    } else if (input < 1 || input > 4) {
      valid = false;
      cout << "Please enter 1-4." << endl;
      continue;
    } else {
      valid = true;
      discardPile.setSuit(static_cast<Suit>(input));
      cout << endl;
    }
  }
}

void CrazyEights::playerWins() {
  std::cout << "\e[1;31mWinner: Player!\e[0m" << std::endl;
}

void CrazyEights::computerTurn() {
  if (discardPile.peak().getRank() == Rank::Eight) {
    // The computer must play the crazy eight suit or another eight
    int eight = computer.searchEight();
    int crazyEightSuit = computer.searchSuit(discardPile.getSuit());

    if (crazyEightSuit != -1)
      discardPile.push(computer.removeCard(crazyEightSuit));
    else if (eight != -1) {
      discardPile.push(computer.removeCard(eight));
      discardPile.setSuit(static_cast<Suit>((rand() % 4) + 1)); // Set the suit to a random suit
    } else {
      try {
        computer.addCard(deck.draw());
      } catch (Deck::DeckEmptyException) { // If there are no more cards compare scores
        compareScores();
      }
    }
  } else { // If no eight was played
    // The computer must play a matching suit, matching rank, or an eight
    int eight = computer.searchEight();
    int suit = computer.searchSuit(discardPile.peak().getSuit());
    int rank = computer.searchRank(discardPile.peak().getRank());

    if (suit != -1)
      discardPile.push(computer.removeCard(suit));
    else if (rank != -1)
      discardPile.push(computer.removeCard(rank));
    else if (eight != -1) {
      discardPile.push(computer.removeCard(eight));
      discardPile.setSuit(static_cast<Suit>((rand() % 4) + 1)); // Set the suit to a random suit
    } else {
      try {
        computer.addCard(deck.draw());
      } catch (Deck::DeckEmptyException) { // If there are no more cards compare scores
        compareScores();
      }
    }
  }

  if (computer.isEmpty())
    computerWins();
  else
    playerTurn();
}

void CrazyEights::computerWins() {
  std::cout << "\e[1;31mWinner: Computer!\e[0m" << std::endl;
}

int CrazyEights::cardToPoints(const Card &card) {
  switch (card.getRank()) {
    case Rank::King:
    case Rank::Queen:
    case Rank::Joker:
    case Rank::Jack:
      return 10;
    case Rank::Ace:
      return 1;
    case Rank::Two:
      return 2;
    case Rank::Three:
      return 3;
    case Rank::Four:
      return 4;
    case Rank::Five:
      return 5;
    case Rank::Six:
      return 6;
    case Rank::Seven:
      return 7;
    case Rank::Eight:
      return 50;
    case Rank::Nine:
      return 9;
    case Rank::Ten:
      return 10;
  }
}

int CrazyEights::scoreHand(const Hand &hand) {
  int total = 0;

  try {
    for (size_t i = 0; ; ++i)
      total += cardToPoints(hand.selectCard(i));
  } catch (Hand::CardOutOfRangeException) {
    return total;
  }
}

void CrazyEights::compareScores() {
  int playerScore = scoreHand(player);
  int computerScore = scoreHand(computer);

  if (playerScore < computerScore)
    playerWins();
  else if (computerScore < playerScore)
    computerWins();
  else
    std::cout << "\e[1;31mIt's a tie!\e[0m" << std::endl;
}
