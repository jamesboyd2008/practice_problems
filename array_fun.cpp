#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main ()
{
  int arr[2];
  cout << "arr: " << arr << endl;

  arr[0] = 27;
  arr[1] = 9000;
  cout << "arr[0]: " << arr[0] << endl;
  cout << "arr[1]: " << arr[1] << endl;

  int twoD[5][2];
  // [0][1]
  // [2][3]
  // [4][5]
  // [6][7]
  // [8][9]
  int count = 0;

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      twoD[i][j] = count;
      count ++;
      if (j == 1)
        cout << "[" << twoD[i][j] << "]\n";
      else
        cout << "[" << twoD[i][j] << "]";
    }
  }

}
