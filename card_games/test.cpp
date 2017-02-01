#include <exception>
#include "gtest/gtest.h"
#include "Card.h"
#include "Deck.h"
#include "War.h"
#include "BlackJack.h"

using namespace std;

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

TEST(CardTest,LessOperator) {
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
  ASSERT_EQ(*deck.pick(), Card(Rank::Ace, Suit::Clubs));
}

TEST(DeckTest, PickRandom) {
  Deck deck = Deck();
  Card card1 = *deck.pick_random(), card2 = *deck.pick_random();

  ASSERT_FALSE((card1 == Card(Rank::Ace, Suit::Clubs)) && (card2 == Card(Rank::Two, Suit::Clubs)));
}

TEST(DeckTest, Shuffle) {
  Deck deck = Deck();
  deck.shuffle();
  Card card1 = *deck.pick(), card2 = *deck.pick();

  ASSERT_FALSE((card1 == Card(Rank::Ace, Suit::Clubs)) && (card2 == Card(Rank::Two, Suit::Clubs)));
}

TEST(DeckTest, FiftyTwoCards) {
  Deck deck = Deck();

  for(size_t i = 0; i < 52; i++)
    ASSERT_TRUE(deck.pick() != nullptr);

  ASSERT_TRUE(deck.pick() == nullptr);
}

}

namespace WarTests {

TEST(WarTest, Constructor) {
  ASSERT_NO_THROW(War());
}

TEST(WarTest, Play) {
  War().play();
}

}

namespace BlackJackTest {

// The fixture for testing class War.
// Allows the usage of cin by inserting text into input
class BlackJackTest : public ::testing::Test {
 protected:
  std::streambuf* original_input;
  std::istringstream input;

  void SetUp() {
    original_input = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
  }

  void TearDown() {
    std::cin.rdbuf(original_input);
  }
};

TEST_F(BlackJackTest, Constructor) {
  ASSERT_NO_THROW(BlackJack());
}

TEST_F(BlackJackTest, Play) {
  BlackJack blackJack = BlackJack();

  this->input.str("2\n");
  blackJack.play();
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
