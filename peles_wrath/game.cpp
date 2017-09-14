// This is driver for the game
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "zone.h"
#include "zone_map.h"
#include "player.h"
using namespace std;

void move();
void challenge();
bool handleResponse(string response);

Player player; // instantiates the player

int main()
{
  unsigned seed;
  seed = time(0);
  srand(seed);
  ZoneMap theMap; // instantiates the map

  cout << "\x1B[2J\x1B[H"; // clears the screen
  cout << "You find yourself on a tropical island...\n";
  cin.get();
  cout << "An old lady says, \"You must score 100 points.\"\n";
  cin.get();

  player.setName(); // get user name

  cout << player.getName() << ", you see a lava flow heading your way.\n";
  cin.get();

  while (player.getPoints() < 10)
  {
    // navigate
    // get prompted for question
    // answer question
    // die or keep going
    // increment score
    move(); // sets players location
    // challenge(); // asks them a question
  }

  cout << "Congratuations, " << player.getName()
       << "! You swam to Maui.\n\nTHE END\n\n";

  return 0;
}

/**
 *  prompts user for input and gets their next move.
 */
void move()
{
  string choice;
  bool validChoice = false;
  bool dry = true;

  cout << "\x1B[2J\x1B[H"; // clears the screen
  cout << player;

  int location[2];
  location[0] = player.getLocation()[0];
  location[1] = player.getLocation()[1];

  while
  (
    (validChoice == false || dry == false) &&
    player.getPoints() < 10
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
      cout << "\x1B[2J\x1B[H"; // clears the screen
      cout << player;
      cout << "You're in the ocean! Press enter to swim!\n";
      cin.get();
      player.incrementPoints();
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
    else if (location[1] == 0) // player borders the left edge
    {
      cout << "Choose a direction: N, S, or E: ";
      cin >> choice;
      if (choice == "N" || choice == "S" || choice == "E")
        validChoice = true;
    }
    else if (location[0] == 0) // player borders the top edge
    {
      cout << "Choose a direction: S, E, or W: ";
      cin >> choice;
      if (choice == "S" || choice == "E" || choice == "W")
        validChoice = true;
    }
    else if (location[1] == 4) // player borders the right edge
    {
      cout << "Choose a direction: N, S, or W: ";
      cin >> choice;
      if (choice == "N" || choice == "S" || choice == "W")
        validChoice = true;
    }
    else if (location[0] == 4) // player borders the bottom edge
    {
      cout << "Choose a direction: N, E, or W: ";
      cin >> choice;
      if (choice == "N" || choice == "E" || choice == "W")
        validChoice = true;
    }
    else // player is in a non-edge zone
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

}

/**
 *  handles the user's response to the question
 */
void handleResponse()
{

}
