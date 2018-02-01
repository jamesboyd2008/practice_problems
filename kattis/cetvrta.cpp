/*
This program turns a right triangle into a rectangle.

This puzzle is from https://open.kattis.com/problems/cetvrta

Title: Cetvrta
Mirko needs to choose four points in the plane so that they form a rectangle with sides parallel to the axes. He has already chosen three points and is confident that he hasn’t made a mistake, but is having trouble locating the last point. Help him.

Input
Each of the three points already chosen will be given on a separate line. All coordinates will be integers between 1 and 1000.

Output
Output the coordinates of the fourth vertex of the rectangle.

Sample Input 1	Sample Output 1
5 5             7 7
5 7
7 5

Sample Input 2	Sample Output 2
30 20           30 10
10 10
10 20
*/

#include "iostream"

using namespace std;

int main()
{
  int corners[3][2];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> corners[i][j];
    }
  }

  int coords[2];
  int coord_1 = 0, coord_2 = 0, different;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (corners[j][i] == corners[0][i])
      {
        coord_1++;
      }
      else
      {
        different = j;
        coord_2++;
      }
    }
    coords[i] = (coord_1 > coord_2 ? corners[different][i] : corners[0][i]);
    coord_1 = coord_2 = 0;
  }

  cout << coords[0] << " " << coords[1] << endl;

  return 0;
}
