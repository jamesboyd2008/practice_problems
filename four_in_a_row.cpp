// 4 in a row -- let the wookie win
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int correctMove(char testBoard[][5]);
// returns your only option, an integer.

bool isSafeMove(char testBoard[][5], int row, int column);
// returns whether putting an 'O' there is a good idea.

bool isSafeHorizontally(char testBoard[][5], int row, int column);
// returns whether that position is Horizontally safe.

bool isSafeVertically(char testBoard[][5], int row, int column);
// returns whether that position is Vertically safe.

bool isSafeDiagonally(char testBoard[][5], int row, int column);
// returns whether that position is Diagonally safe.

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

// returns an integer, the correctMove.
int correctMove(char testBoard[][5])
{
  // test to see if the argument is valid
  // cout << testBoard[0][2] << testBoard[2][2] << endl;

  /** Iterate over rows and columns, until you find an asterisk.
  Then, see if you can move there without getting your arms ripped out.
  If you can move there, return that value.
  If you can't move there, keep looking. */
  for (int row = 0; row < 5; row++)
  {
    for (int column = 0; column < 5; column++)
    {
      // is this square an asterisk?
      if (testBoard[row][column] == '*')
      {
        if (isSafeMove(testBoard, row, column))
        {
          cout << "[" << row << "][" << column << "]\n";
          // return (column + 1 + (row * 5));
        }
      }
    }
  }

  return 0;
}

// returns whether putting an 'O' there is a good idea.
bool isSafeMove(char testBoard[][5], int row, int column)
{
  // check horizontal
  // check vertical
  // check diagonal
  if (isSafeHorizontally(testBoard, row, column))
  {
    if (isSafeVertically(testBoard, row, column))
    {
      if (isSafeDiagonally(testBoard, row, column))
      {
        return true;
      }
    }
  }
    
  return false;
}

// returns whether that position is Horizontally safe.
bool isSafeHorizontally(char testBoard[][5], int row, int column)
{
  // go as far as you can to the left as long as it's an O
  // go as far as you can to the right as long as it's an O or an *
    // if you get 4 in a row, return false
  // otherwise, return true
  // bool oToTheLeft = true;
  // while (oToTheLeft == true)
  // {
  //
  // }
  // return true;
  return true;
}

// returns whether that position is Vertically safe.
bool isSafeVertically(char testBoard[][5], int row, int column)
{
  // go as far as you can up as long as it's an O
  // go as far as you can down as long as it's an O or an *
    // if you get 4 in a row, return false
  // otherwise, return true
  return true;
}

// returns whether that position is Diagonally safe.
bool isSafeDiagonally(char testBoard[][5], int row, int column)
{
  // check Northwest/Southeast
  // check SouthWest/Northeast
  return true;
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
