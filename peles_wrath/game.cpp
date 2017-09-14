// This is the driver for the game
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "zone.h"
#include "zone_map.h"
#include "player.h"
using namespace std;

// unsigned seed;
// seed = time(0);
// srand(seed);

// global(s) ...sorry
Player player; // instantiates the player
ZoneMap theMap; // instantiates the map

void move();
void challenge();
void handleResponse(Zone zone, int ttl, int timeStart);
void swim();

int main()
{

  cout << "\x1B[2J\x1B[H"; // clears the screen
  cout << "You find yourself on a tropical island...\n";
  cin.get();
  cout << "An old lady says, \"You must score 100 points.\"\n";
  cin.get();

  player.setName(); // get user name

  cout << player.getName() << ", you see a lava flow heading your way.\n";
  cin.get();

  while (player.getPoints() < 99)
  {
    move(); // sets players location
    if (player.getPoints() < 99)
      challenge(); // asks them a question
  }

  if (player.isAlive())
  {
    swim();
    cout << "Congratuations, " << player.getName()
         << "! You swam to Maui.\n\nTHE END\n\n";
  }
  else
  {
    cout << "You died in the lava flow.\n\nTHE END\n\n";
  }

  return 0;
}

/**
 *  prompts user for input and gets their next move. Sets their new location.
 */
void move()
{
  string choice;
  bool validChoice = false;
  bool dry = true;

  // clears the screen
  cout << "\x1B[2J\x1B[H";
  cout << player << "\n\n";

  int location[2];
  location[0] = player.getLocation()[0];
  location[1] = player.getLocation()[1];

  while
  (
    (validChoice == false || dry == false) &&
    player.getPoints() < 99
  )
  {
    // player is in the top left corner
    if (location[0] == 0 && location[1] == 0)
    {
      cout << "Choose a direction: S, or E: ";
      cin >> choice;
      if (choice == "S" || choice == "E")
        validChoice = true;
    }
    // player is in the top right corner
    else if (location[0] == 0 && location[1] == 4)
    {
      cout << "Choose a direction: S, or W: ";
      cin >> choice;
      if (choice == "S" || choice == "W")
        validChoice = true;
    }
    // player is in the bottom right corner
    else if (location[0] == 4 && location[1] == 4)
    {
      // swim to Maui!
      swim();
      dry = false;
    }
    // player is in the bottom left corner
    else if (location[0] == 4 && location[1] == 0)
    {
      cout << "Choose a direction: N, or E: ";
      cin >> choice;
      if (choice == "N" || choice == "E")
        validChoice = true;
    }
    // player borders the left edge
    else if (location[1] == 0)
    {
      cout << "Choose a direction: N, S, or E: ";
      cin >> choice;
      if (choice == "N" || choice == "S" || choice == "E")
        validChoice = true;
    }
    // player borders the top edge
    else if (location[0] == 0)
    {
      cout << "Choose a direction: S, E, or W: ";
      cin >> choice;
      if (choice == "S" || choice == "E" || choice == "W")
        validChoice = true;
    }
    // player borders the right edge
    else if (location[1] == 4)
    {
      cout << "Choose a direction: N, S, or W: ";
      cin >> choice;
      if (choice == "N" || choice == "S" || choice == "W")
        validChoice = true;
    }
    // player borders the bottom edge
    else if (location[0] == 4)
    {
      cout << "Choose a direction: N, E, or W: ";
      cin >> choice;
      if (choice == "N" || choice == "E" || choice == "W")
        validChoice = true;
    }
    // player is in a non-edge zone
    else
    {
      cout << "Choose a direction: N, S, E, or W: ";
      cin >> choice;
      if (choice == "N" || choice == "S" || choice == "E" || choice == "W")
        validChoice = true;
    }
  }

  int row = location[0];
  int column = location[1];
  // set the player's new location
  if (choice == "N")
    row--;
  else if (choice == "S")
    row++;
  else if (choice == "E")
    column++;
  else // player chose W
    column--;

  player.setLocation(row, column);
}

/**
 *  asks the user a question
 */
void challenge()
{
  int row, column;
  row = player.getLocation()[0];
  column = player.getLocation()[1];

  // This is the zone in which the player is currently located.
  Zone zone = theMap.getZone(row, column);

  // prints a description of the players surroundings
  cout << endl << zone.getDescription() << "\n";

   // time to live
  // int ttl = zone.getTtl();
  cout << endl;
  cout << zone.getQuestion() << endl;
  handleResponse(zone, zone.getTtl(), time(0));
}

/**
 *  handles the user's response to the question takine the current zone
 *  as an argument.
 *  @param Zone
 */
void handleResponse(Zone zone, int ttl, int timeStart)
{
  bool correct = zone.getResponse();
  int timesUp = time(0);
  cin.get();

  if (correct && player.getPoints() < 99)
    player.incrementPoints();
  else
    player.decrementPoints();

  // player is consumed by lava if they are too slow
  if (timesUp - timeStart > ttl)
  {
    player.isDead();
    cout << "You took too long to respond.\n"
         << "Out with the old, in with the new: Pele's coming through!\n";
  }

  if (player.getPoints() < 0 || !player.isAlive())
  {
    player.isDead();
    player.setPoints(100);
  }
}

/**
 *  the function simulates swimming
 */
void swim()
{
  // clears the screen
  cout << "\x1B[2J\x1B[H";
  cout << player;
  cout << "You're in the ocean! Press enter to swim!\n";
  cin.get();
  player.incrementPoints();
}
