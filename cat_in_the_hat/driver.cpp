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
#include "gameSimulation.cpp"
#include "outputFileWriter.cpp"

using namespace std;

int main()
{
  string fileName, rhyme, winner = "Alice";

  // get the test case file name from the user
  cout << "What is the name of the rhyme file? ";
  cin >> fileName;

  int playerCount, wordCount;
  vector<ListNodePtr> players;

  // read the test case file
  players = inputFileReader
    (fileName, players, &playerCount, &wordCount, &rhyme);

  // handle corner case in which nobody wants to play with Alice
  // i.e., there are not at least two players
  if (players.size() < 2)
  {
    cout << "Sorry, Alice. Nobody else wants to play at this time.\n";
    return 0;
  }

  // determine how to win
  int winningPosition = gameSimulation(players, wordCount, &winner);

  // write the results to a file
  outputFileWriter(playerCount, rhyme, winningPosition, &winner);

  cout << "The solution is in results.txt\n";

  return 0;
}
