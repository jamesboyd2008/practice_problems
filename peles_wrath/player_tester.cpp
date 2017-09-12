// This is a test driver for the Player class.
#include "player.h"
#include <iostream>
using namespace std;

int main()
{
  Player player;
  player.setName();
  cout << "Your name is " << player.getName() << ".\n";
  player.decrementPoints();
  cout << "You have " << player.getPoints() << " points.\n";
  player.incrementPoints();
  player.incrementPoints();
  cout << "You have " << player.getPoints() << " points.\n";
  player.setLocation(5, 5);
  cout << "You're at zone " << player.getLocation()[0]
                          << player.getLocation()[1]
                          << ".\n";

  cout << player;
  return 0;
}
