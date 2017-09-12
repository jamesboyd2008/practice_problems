// This is a test driver for the Player class.
#include "player.h"

int main()
{
  Player player;
  player.setName();
  cout << "Your name is " << player.getName() << ".\n";
  player.setPoints(400);
  cout << "You have " << player.getPoints() << " points.\n";
  player.setLocation(5, 5);
  cout << "Your at zone " << player.getLocation()[0]
                          << player.getLocation()[1]
                          << ".\n";

  cout << player;
  return 0;
}
