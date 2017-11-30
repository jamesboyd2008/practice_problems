// This file contains the Card class specification and implementation.

#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
  Card();
  Card(string a_suit, string a_value, int some_points);
  string get_suit();
  void set_suit(string a_suit);
  string get_value();
  void set_value(string a_value);
  int get_points();
  void set_points(int some_points);
  friend ostream &operator<<(ostream &out, Card &card);
private:
  string suit;
  string value;
  int points; // 2-10, Jack: 11, Queen: 12, King: 13, Ace: 14
};

// default constructor
Card::Card()
{
  suit = "spades";
  value = 'A';
  points = 13;
}

// overloaded constructor
Card::Card(string a_suit, string a_value, int some_points)
{
  suit = a_suit;
  value = a_value;
  points = some_points;
}

// accessor function
string Card::get_suit()
{
  return suit;
}

// mutator function
void Card::set_suit(string a_suit)
{
  suit = a_suit;
}

// accessor function
string Card::get_value()
{
  return value;
}

// mutator function
void Card::set_value(string a_value)
{
  value = a_value;
}

// accessor function
int Card::get_points()
{
  return points;
}

// mutator function
void Card::set_points(int some_points)
{
  points = some_points;
}

// overloaded insertion operator
ostream &operator<<(ostream &out, Card &card)
{
  const char spades[4]   = "\u2664",
             hearts[4]   = "\u2661",
             diamonds[4] = "\u2662",
             clubs[4]    = "\u2667";

  out << "card:  " << card.get_value();

  string suit = card.get_suit();

  if (suit == "spades")
    out << spades;
  else if (suit == "hearts")
    out << hearts;
  else if (suit == "diamonds")
    out << diamonds;
  else if (suit == "clubs")
    out << clubs;
  else
    out << "indeterminate suit";

  out << "  points: " << card.get_points();

  return out;
}
