// This is the Player class
#ifndef _Player_H
#define _Player_H
#include <iostream>
#include <sstream>
// #include <string>
using namespace std;

class Player
{
  private:
    string name;
    int points;
    int location[2];
  public:
    Player();
    void setName();
    string getName();
    void setPoints(int newPoints);
    int getPoints();
    void setLocation(int row, int column);
    int * getLocation();
    friend ostream &operator<<(ostream &output, Player player);
};

/**
 *  a contruscotr, initializes the player's location at [0, 0] and their
 *  points at 0.
 *  @return Player
 */
Player::Player()
{
  location[0] = 0;
  location[1] = 0;
  points = 0;
}

/**
 *  mutator function that sets the character's name.
 */
void Player::setName()
{
  string response;
  cout << "What's your character's name? ";
  cin >> response;
  name = response;
}

/**
 *  an accessor function that returns a string, the character's name.
 *  @return name
 */
string Player::getName()
{
  return name;
}

/**
 *  a mutator function that sets they players points, taking an integer
 *  as an argument.
 *  @param newPoints
 */
void Player::setPoints(int newPoints)
{
  points += newPoints;
}

/**
 *  an accessor function that returns an integer, the charater's points.
 * @return points
 */
int Player::getPoints()
{
  return points;
}

/**
 *  a mutator function that sets the player's location, taking two integers
 *  as arguments.
 */
void Player::setLocation(int row, int column)
{
  location[0] = row;
  location[1] = column;
}

int * Player::getLocation()
{
  return location;
}

// overloads the insertion operator (<<) to recognize an ostream object on
// the left, and an Player object on the right, so that when one prints an
// Player object, the private members of that object are displayed.
ostream &operator<<(ostream &output, Player player)
{
  output << "Your name is " << player.name << ".\n";
  output << "You have " << player.points << " points.\n";
  output << "Your location is zone ["
         << player.location[0] << "][" << player.location[1] << "].\n";
  return output;
}
#endif
