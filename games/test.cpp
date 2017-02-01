#include <stdexcept>

#include "gtest/gtest.h"
#include "Card.h"
#include "Deck.h"
#include "War.h"
#include "BlackJack.h"
#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "RPS.h"
#include "Hand.h"
#include "CrazyEights.h"

using namespace std;

// Allows the usage of cin by inserting text into input
class IOTest: public ::testing::Test {
 protected:
  std::streambuf *original_input;
  std::istringstream input;

  void SetUp() {
    original_input = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
  }

  void TearDown() {
    std::cin.rdbuf(original_input);
  }
};

namespace CardTests {

TEST(CardTest, DefaultConstructorIsJoker) {
  Card card;
  ASSERT_NO_THROW(card = Card());
  ASSERT_EQ(card.getRank(), Rank::Joker);
  ASSERT_EQ(card.getSuit(), Suit::Joker);
}

TEST(CardTest, ParametrizedConstructor) {
  Card card;

  for (size_t rank = 1; rank <= 13; rank++) {
    for (size_t suit = 1; suit <= 4; suit++) {
      ASSERT_NO_THROW(card = Card(RANK[rank], SUIT[suit]));

      ASSERT_EQ(card.getRank(), RANK[rank]);
      ASSERT_EQ(card.getSuit(), SUIT[suit]);
    }
  }
}

TEST(CardTest, ParametrizedConstructorThrowsException) {
  Card card;

  ASSERT_THROW(Card(Rank::Joker, Suit::Clubs), std::invalid_argument);
}

TEST(CardTest, EqualToOperator) {
  ASSERT_TRUE(Card() == Card());
}

TEST(CardTest, LessOperator) {
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) < Card(Rank::Two, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Two, Suit::Spades) < Card(Rank::Ace, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Ace, Suit::Clubs) < Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Ace, Suit::Spades) < Card(Rank::Ace, Suit::Clubs));
}

TEST(CardTest, LessOrEqualOperator) {
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) <= Card(Rank::Ace, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) <= Card(Rank::Two, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Two, Suit::Spades) <= Card(Rank::Ace, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Ace, Suit::Clubs) <= Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Ace, Suit::Spades) <= Card(Rank::Ace, Suit::Clubs));
}

TEST(CardTest, GreaterOperator) {
  ASSERT_FALSE(Card(Rank::Ace, Suit::Spades) > Card(Rank::Two, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Two, Suit::Spades) > Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Ace, Suit::Clubs) > Card(Rank::Ace, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) > Card(Rank::Ace, Suit::Clubs));
}

TEST(CardTest, GreaterOrEqualOperator) {
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) >= Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Ace, Suit::Spades) >= Card(Rank::Two, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Two, Suit::Spades) >= Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(Card(Rank::Ace, Suit::Clubs) >= Card(Rank::Ace, Suit::Spades));
  ASSERT_TRUE(Card(Rank::Ace, Suit::Spades) >= Card(Rank::Ace, Suit::Clubs));
}

TEST(CardTest, InsertionOperator) {
  stringstream output;

  // Joker card
  Card card = Card();
  output << card;
  ASSERT_EQ(output.str(), "Joker");
  output.str(std::string());

  // Ace of Spades
  card = Card(Rank::Ace, Suit::Spades);
  output << card;
  ASSERT_EQ(output.str(), "Ace of Spades");
  output.str(std::string());
}

}

namespace DeckTests {

TEST(DeckTest, Constructor) {
  ASSERT_NO_THROW(Deck());
}

TEST(DeckTest, Pick) {
  Deck deck = Deck();
  ASSERT_EQ(deck.draw(), Card(Rank::King, Suit::Spades));
}

TEST(DeckTest, Shuffle) {
  Deck deck = Deck();
  deck.shuffle();
  Card card1 = deck.draw(), card2 = deck.draw();

  ASSERT_FALSE((card1 == Card(Rank::King, Suit::Spades)) && (card2 == Card(Rank::Queen, Suit::Spades)));
}

TEST(DeckTest, FiftyTwoCards) {
  Deck deck = Deck();

  for (size_t i = 0; i < 52; i++)
    ASSERT_NO_THROW(deck.draw());

  ASSERT_THROW(deck.draw(), Deck::DeckEmptyException);
}

}

namespace WarTests {

// The fixture for testing class War.
class WarTest: public IOTest { };

TEST_F(WarTest, Play) {
  this->input.str(string(11, '\n'));
  War();
}

}

namespace BlackJackTests {

// The fixture for testing class BlackJack.
class BlackJackTest: public IOTest { };

TEST_F(BlackJackTest, Play) {
  this->input.str("2\n");
  BlackJack();
}

}

namespace ToolsTests {

TEST(RockTest, Fight) {
  ASSERT_EQ(Rock().fight(new Rock()), 0);
  ASSERT_EQ(Rock().fight(new Paper()), 2);
  ASSERT_EQ(Rock().fight(new Scissors()), 1);
}

TEST(PaperTest, Fight) {
  ASSERT_EQ(Paper().fight(new Rock()), 1);
  ASSERT_EQ(Paper().fight(new Paper()), 0);
  ASSERT_EQ(Paper().fight(new Scissors()), 2);
}

TEST(ScissorsTest, Fight) {
  ASSERT_EQ(Scissors().fight(new Rock()), 2);
  ASSERT_EQ(Scissors().fight(new Paper()), 1);
  ASSERT_EQ(Scissors().fight(new Scissors()), 0);
}

}

namespace RPSTests {

// The fixture for testing class RPS.
class RPSTest: public IOTest { };

TEST_F(RPSTest, Play) {
  for (size_t i = 0; i < 5; i++) {
    this->input.str("r\n");
    RPS();
  }
}

}

namespace HandTests {

TEST(HandTest, Constructor) {
  ASSERT_NO_THROW(Hand hand);
}

TEST(HandTest, AddCard) {
  Hand hand;
  ASSERT_NO_THROW(hand.addCard(Card(Rank::Ace, Suit::Spades)));
}

TEST(HandTest, RemoveCard) {
  Hand hand;

  hand.addCard(Card(Rank::Ace, Suit::Spades));
  ASSERT_EQ(hand.removeCard(0), Card(Rank::Ace, Suit::Spades));
  ASSERT_THROW(hand.removeCard(0), Hand::CardOutOfRangeException);
}

TEST(HandTest, SelectCard) {
  Hand hand;

  hand.addCard(Card(Rank::Ace, Suit::Spades));
  ASSERT_EQ(hand.selectCard(0), Card(Rank::Ace, Suit::Spades));
  ASSERT_NO_THROW(hand.removeCard(0));
}

TEST(HandTest, IsEmpty) {
  Hand hand;

  hand.addCard(Card(Rank::Ace, Suit::Spades));
  ASSERT_FALSE(hand.isEmpty());
  ASSERT_NO_THROW(hand.removeCard(0));
  ASSERT_TRUE(hand.isEmpty());
}

TEST(HandTest, SearchEight) {
  Hand hand;

  ASSERT_EQ(hand.searchEight(), -1);
  hand.addCard(Card(Rank::Eight, Suit::Spades));
  ASSERT_EQ(hand.searchEight(), 0);
}

TEST(HandTest, SearchSuit) {
  Hand hand;

  ASSERT_EQ(hand.searchSuit(Suit::Clubs), -1);
  hand.addCard(Card(Rank::Eight, Suit::Spades));
  ASSERT_EQ(hand.searchSuit(Suit::Clubs), -1);
  ASSERT_EQ(hand.searchSuit(Suit::Spades), 0);
}

TEST(HandTest, SearchRank) {
  Hand hand;

  ASSERT_EQ(hand.searchRank(Rank::Ace), -1);
  hand.addCard(Card(Rank::Two, Suit::Spades));
  ASSERT_EQ(hand.searchRank(Rank::Ace), -1);
  ASSERT_EQ(hand.searchRank(Rank::Two), 0);
}

}

namespace StackTests {

TEST(StackTest, Constructor) {
  ASSERT_NO_THROW(Stack<Card> stack);
}

TEST(StackTest, Push) {
  Stack<Card> stack;
  ASSERT_NO_THROW(stack.push(Card(Rank::Ace, Suit::Spades)));
}

TEST(StackTest, Pop) {
  Stack<Card> stack;
  ASSERT_NO_THROW(stack.push(Card(Rank::Ace, Suit::Spades)));
  ASSERT_EQ(stack.pop(), Card(Rank::Ace, Suit::Spades));
}

TEST(StackTest, Peak) {
  Stack<Card> stack;
  ASSERT_NO_THROW(stack.push(Card(Rank::Ace, Suit::Spades)));
  ASSERT_EQ(stack.peak(), Card(Rank::Ace, Suit::Spades));
  ASSERT_EQ(stack.peak(), Card(Rank::Ace, Suit::Spades));
}

}

namespace DiscardPileTests {

TEST(DiscardPileTest, Constructor) {
  ASSERT_NO_THROW(DiscardPile pile);
}

TEST(DiscardPileTest, GetSuit) {
  DiscardPile pile;
  ASSERT_EQ(pile.getSuit(), Suit::Joker);
}

TEST(DiscardPileTest, SetSuit) {
  DiscardPile pile;
  ASSERT_EQ(pile.getSuit(), Suit::Joker);
  ASSERT_NO_THROW(pile.setSuit(Suit::Spades));
  ASSERT_EQ(pile.getSuit(), Suit::Spades);
}

}
