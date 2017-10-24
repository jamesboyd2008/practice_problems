// returns whether that position is Vertically safe.

using namespace std;

bool isSafeVertically(
  char testBoard[][5],
  int row,
  int column,
  char player = 'O'
)
{
  char opponent = 'X';
  if (player == 'X')
    opponent = 'O';

  // int columnCopy = column;
  int rowCopy = row;

  // cout << "* @: [" << rowCopy << "][" << column << "]\n";
  // will this position NOT make you win?
  // go as far as you can up as it's an O
  // go as far as you can down as long as it's an O or an *
    // if you get 4 in a row, return false
  // otherwise, return true
  bool oAbove = true;
  while (oAbove == true)
  {
    // if ( columnCopy < 1 || testBoard[row][columnCopy - 1] == 'X')
    if ( rowCopy < 1 || testBoard[rowCopy -1 ][column] == opponent)
      oAbove = false;
    else rowCopy--;
  }

  int oCount = 0;
  for (int pleaseNot4 = 0; pleaseNot4 < 4; pleaseNot4++)
  {
    // cout << "vertical?: " << "[" << rowCopy << "][" << column << "]\n";

    // increment O count for every O encountered
    if (testBoard[rowCopy][column] == player)
    oCount++;

    // if this move causes you to win
    if (oCount > 2)
    {
      // cout << "Don\'t move on this column: " << "[" << rowCopy << "][" << column << "]\n";
      return false;
    }

    // if it's the end of the column or you run into an X
    if (rowCopy > 3 || testBoard[rowCopy + 1][column] == opponent)
    {
      // cout << "It's not four in a row.\n";
      break;
    }

    rowCopy++;
  }

  // will this position NOT block the wookie from winning?
  if (player == 'O')
  {
    // if this space LETS the wookie win, then we don't want to block him/her
    if (!isSafeVertically(testBoard, column, row, 'X'))
    {
      // cout << "This move blocks the wookie.\n";
      return false;
    }
  }
  // cout << "column: " << column << endl;
  // cout << "columnCopy: " << columnCopy << endl;
  // cout << "player: " << player << endl;

  return true;
}
