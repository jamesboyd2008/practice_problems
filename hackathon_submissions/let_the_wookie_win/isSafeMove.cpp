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
