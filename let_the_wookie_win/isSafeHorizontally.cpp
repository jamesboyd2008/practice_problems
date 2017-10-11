// returns whether that position is Horizontally safe.

using namespace std;

bool isSafeHorizontally(
  char testBoard[][5],
  int row,
  int column,
  char player = 'O'
)
{
  char opponent = 'X';
  if (player == 'X')
    opponent = 'O';

  int columnCopy = column;

  // will this position NOT make you win?
  // go as far as you can to the left as long as it's an O
  // go as far as you can to the right as long as it's an O or an *
    // if you get 4 in a row, return false
  // otherwise, return true
  bool oToTheLeft = true;
  while (oToTheLeft == true)
  {
    // if ( columnCopy < 1 || testBoard[row][columnCopy - 1] == 'X')
    if ( columnCopy < 1 || testBoard[row][columnCopy - 1] == opponent)
      oToTheLeft = false;
    else columnCopy--;
  }

  int oCount = 0;
  for (int pleaseNot4 = 0; pleaseNot4 < 4; pleaseNot4++)
  {
    cout << "horizontal?: " << "[" << row << "][" << columnCopy << "]\n";

    // increment O count for every O encountered
    if (testBoard[row][columnCopy] == player)
    oCount++;

    // if this move causes you to win
    if (oCount > 2)
    {
      cout << "Don\'t move here: " << "[" << row << "][" << columnCopy << "]\n";
      return false;
    }

    // if it's the end of the row or you run into an X
    if (columnCopy > 3 || testBoard[row][columnCopy + 1] == opponent)
    {
      // cout << "It's not four in a row.\n";
      break;
    }

    columnCopy++;
  }

  // will this position NOT block the wookie from winning?
  // if (player == 'O')
  // {
  //   // if this space LETS the wookie win
  //   if (!isSafeHorizontally(testBoard, column, row, 'X'))
  //     return false;
  // }
  // cout << "column: " << column << endl;
  // cout << "columnCopy: " << columnCopy << endl;
  // cout << "player: " << player << endl;

  return true;
}
