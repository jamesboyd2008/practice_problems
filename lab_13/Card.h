// This file contains the Card class specification and implementation.

#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
  // define default constructor
  // define overloaded constructor
  // define accessors
  // define mutators
  // define overloaded stream insertion operator
  Card();
  Card(string a_suit, char a_value, int some_points);
  string get_suit();
  void set_suit(string a_suit);
  char get_value();
  void set_value(char a_value);
  int get_points();
  void set_points(int some_points);
  friend ostream &operator<<(ostream &out, Card &card);
private:
  string suit;
  char value;
  int points; // 2-10, Jack: 10, Queen: 11, King: 12, Ace: 13
};

// default constructor
Card::Card()
{
  suit = "spades";
  value = 'A';
  points = 13;
}

// overloaded constructor
Card::Card(string a_suit, char a_value, int some_points)
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
char Card::get_value()
{
  return value;
}

// mutator function
void Card::set_value(char a_value)
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

  out << "value:  " << card.get_value()  << endl
      << "suit:   ";

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

  out << endl;
  out << "points: " << card.get_points() << endl;

  return out;
}
