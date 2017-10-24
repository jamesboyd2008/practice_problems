// 4 in a row -- let the wookie win
#include <iostream>
#include <vector>
#include <string>
#include "isSafeHorizontally.cpp"
#include "isSafeVertically.cpp"
#include "isSafeDiagonally.cpp"
#include "isSafeMove.cpp"
#include "correctMove.cpp"

using namespace std;

int main()
{
  int result;
  string board;
  vector<string> boards;
  cout << "Enter some boards:\n";

  do
  {
    getline(cin, board);
    boards.push_back(board); // last board is "Finished"
  } while (board != "Finished");

  char boardOfAnalysis[5][5];
  int focalSquare = 0;

  // iterate over every board
  // (boards.size() - 1) is used because the last board is the string "Finished"
  for (int focalBoard = 0; focalBoard < boards.size() - 1; focalBoard++)
  {
    // put each square into the correct row
    for (int focalRow = 0; focalRow < 5; focalRow++)
    {
      // put each square into correct column
      for (int focalColumn = 0; focalColumn < 5; focalColumn++)
      {
        // cout << boards[focalBoard].at(focalSquare) << " ";
        boardOfAnalysis[focalRow][focalColumn] = boards[focalBoard].at(focalSquare);
        focalSquare += 2;
      }
      // cout << endl;
    }
    focalSquare = 0;

    cout << "\nNext Board: \n";

    // get the solution for boardOfAnalysis
    result = correctMove(boardOfAnalysis);
    // cout << result << endl;
  }

  return 0;
}

/**
A test case as a 5x5:
X O * X X
O O X X *
O O * X X
O X O O X
X O O X O

The same test case as a 1x25:
X O * X X O O X X * O O * X X O X O O X X O O X O
*/

/**
A second test case as a 5x5:
X X X * O
O * * O X
O O X * X
O * X X O
* X O O O

The same test case as a 1x25:
X X X * O O * * O X O O X * X O * X X O * X O O O
*/

/**
Both test cases:
X O * X X O O X X * O O * X X O X O O X X O O X O
X X X * O O * * O X O O X * X O * X X O * X O O O
Finished
*/

/**
test case where C3PO musn't accidentally win:
X O * X X O O X X * O O * X X O X O O X X O O X O
X X X * O O * O O X O O X * X O * X X O * X O O O
Finished
*/
