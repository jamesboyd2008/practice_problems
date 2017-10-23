/*
This program simulates a game and tells the user how to win.

For input, you will be given a file with a rhyme. For each particular
rhyme, you need to determine where Alice needs to stand in line in order to
win the game for any given number of friends between 2 and 10. For each
input rhyme, save your results to a file.

*/
#include <fstream>
#include <iostream>
#include <vector>
#include "list_node.h" // re-using code from Lab 6
#include "inputFileReader.cpp"

using namespace std;

/*
handle situation in which no one wants to play
up to 10 friends

read input from file
 - input file contains:
    - n number of people playing
    - the rhyme

make player struct
  - original index property

make circular linked list of n players


loop through players until one remains
 - eliminate someone each go around

output result to file
  - "[result index] is the position in which Alice should stand when
    playing the game with [n] players using the rhyme [rhyme]."
*/
int main()
{
  string fileName;
  cout << "What is the name of the rhyme file? ";
  cin >> fileName;

  int playerCount, wordCount;
  vector<ListNodePtr> players;
  players = inputFileReader(fileName, players, &playerCount, &wordCount);

  if (players.size() == 0)
  {
    cout << "Sorry, Alice. Nobody else wants to play at this time.\n";
    return 0;
  }

  cout << "playerCount in main: " << playerCount << endl;
  cout << "wordCount in main: " << wordCount << endl;

  for (int i = 0; i < players.size(); i++)
  {
    cout << players[i]->quantity << "\n";
  }

  printList(players[9]);

// pickup here
// You've got your circular linked list.  Now start eliminating players




  return 0;
}
