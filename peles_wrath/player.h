// This is the Player class
#ifndef _Player_H
#define _Player_H
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

class Player
{
  private:
    string name;
    int points;
    int location[2];
    int startTime;
  public:
    Player();
    void setName();
    string getName();
    void decrementPoints();
    void incrementPoints();
    int getPoints();
    void setLocation(int row, int column);
    int * getLocation();
    friend ostream &operator<<(ostream &output, Player player);
};

/**
 *  a contructor, initializing the player's location at [0, 0],
 *  their start time at the point of initializatoin, and their
 *  points at 10.
 *  @return Player
 */
Player::Player()
{
  location[0] = 0;
  location[1] = 0;
  startTime = time(0);
  points = 0;
}

/**
 *  mutator function that sets the character's name.
 */
void Player::setName()
{
  string response;
  cout << "What's your name? ";
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
 *  a mutator function that reduces the players points.
 */
void Player::decrementPoints()
{
  points -= 1;
}

/**
 *  a mutator function that increases the players points.
 */
void Player::incrementPoints()
{
  points += 1;
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
         << player.location[0] << "][" << player.location[1] << "].\n"
         << "You  must reach  zone [4][4]\n\n";
  return output;
}
#endif
