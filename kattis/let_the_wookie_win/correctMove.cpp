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
          // cout << "[" << row << "][" << column << "]\n";
          // return (column + 1 + (row * 5));
        }
      }
    }
  }

  return 0;
}
