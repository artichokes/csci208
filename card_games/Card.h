#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

// Card ranks
// Joker = 0, Ace = 1, ..., King = 13
enum class Rank {
  Joker, Ace, Two, Three, Four, Five, Six,
  Seven, Eight, Nine, Ten, Jack, Queen, King
};

const Rank RANK[14] = {Rank::Joker, Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
                       Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King};

// Inserts the card rank into a stream as a string
std::ostream &operator<<(std::ostream &os, Rank rank);

// Card suits
// Joker = 0, ..., Spades = 4
enum class Suit {
  Joker,
  Clubs,
  Diamonds,
  Hearts,
  Spades
};

const Suit SUIT[5] = {Suit::Joker, Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades};

// Inserts the card suit into a stream as a string
std::ostream &operator<<(std::ostream &os, Suit suit);

// Card class
class Card {
 public:
  // Creates a Joker card
  Card();
  // Creates a new card with the provided rank and suit
  // @param rank the rank of the card
  // @param suit the suit of the card
  // @throws invalid_argument if invalid argument is given
  Card(Rank rank, Suit suit);

  // Gets the rank of the card
  // @return The rank of the card
  Rank getRank() const;
  // Gets the suit of the card
  // @return The suit of the card
  Suit getSuit() const;

  // Equality operator
  // @return True if card rank and suit are equal
  bool operator==(const Card &card) const;
  // Comparision operators
  // Compares rank of cards. If ranks are equal compare suits.
  friend bool operator<(const Card &L, const Card &R);
  friend bool operator<=(const Card &L, const Card &R);
  friend bool operator>(const Card &L, const Card &R);
  friend bool operator>=(const Card &L, const Card &R);

  // Inserts the card into a stream as a string
  friend std::ostream &operator<<(std::ostream &os, const Card &card);
 private:
  Rank rank;
  Suit suit;

  // Sets the rank of the card
  // @param rank the rank of the card
  void setRank(Rank rank);
  // Sets the suit of the card
  // @param suit the suit of the card
  void setSuit(Suit suit);
};

#endif //CARD_H
