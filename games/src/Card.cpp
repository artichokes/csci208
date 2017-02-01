#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Card.h"

// @formatter:off

std::ostream &operator<<(std::ostream &os, Rank rank) {
  switch (rank) {
    case Rank::Joker: return os << "Joker";
    case Rank::Ace: return os << "Ace";
    case Rank::Two: return os << "Two";
    case Rank::Three: return os << "Three";
    case Rank::Four: return os << "Four";
    case Rank::Five: return os << "Five";
    case Rank::Six: return os << "Six";
    case Rank::Seven: return os << "Seven";
    case Rank::Eight: return os << "Eight";
    case Rank::Nine: return os << "Nine";
    case Rank::Ten: return os << "Ten";
    case Rank::Jack: return os << "Jack";
    case Rank::Queen: return os << "Queen";
    case Rank::King: return os << "King";
  }
}

std::ostream &operator<<(std::ostream &os, Suit suit) {
  switch (suit) {
    case Suit::Joker: return os << "Joker";
    case Suit::Clubs: return os << "Clubs";
    case Suit::Diamonds: return os << "Diamonds";
    case Suit::Hearts: return os << "Hearts";
    case Suit::Spades: return os << "Spades";
  }
}

// @formatter:on

Card::Card() : rank(Rank::Joker), suit(Suit::Joker) { }

Card::Card(Rank rank, Suit suit) {
  // If the rank or suit is Joker, the card's suit and rank must be set to Joker
  if (((rank == Rank::Joker) && (suit != Suit::Joker)) ||
      ((suit == Suit::Joker) && (rank != Rank::Joker))) {
    throw std::invalid_argument("Rank and suit must both be Joker");
  } else {
    this->rank = rank;
    this->suit = suit;
  }
}

Rank Card::getRank() const { return this->rank; }

Suit Card::getSuit() const { return this->suit; }

bool Card::operator==(const Card &card) const {
  return this->getRank() == card.getRank() &&
      this->getSuit() == card.getSuit();
}

bool operator<(const Card &L, const Card &R) {
  if (L.getRank() == R.getRank())
    return L.getSuit() < R.getSuit();
  else
    return L.getRank() < R.getRank();
}

bool operator<=(const Card &L, const Card &R) {
  return (L < R) || (L == R);
}

bool operator>(const Card &L, const Card &R) {
  if (L.getRank() == R.getRank())
    return L.getSuit() > R.getSuit();
  else
    return L.getRank() > R.getRank();
}

bool operator>=(const Card &L, const Card &R) {
  return (L > R) || (L == R);
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
  if ((card.getRank() == Rank::Joker) || (card.getSuit() == Suit::Joker))
    return os << "Joker";
  else {
    std::stringstream out;
    out << card.getRank() << " of " << card.getSuit();
    return os << out.str();
  }
}

void Card::setRank(Rank rank) { this->rank = rank; }

void Card::setSuit(Suit suit) { this->suit = suit; }
