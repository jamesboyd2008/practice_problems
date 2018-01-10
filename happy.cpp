/*
This program calculate the number of ways the letters in the word "fivey"
can be re-arranged.
*/

#include <iostream>

using namespace std;

int main()
{
  char happy[5] = { 'F', 'I', 'V', 'E', 'Y' };
  int count = 0;

  for (int h = 0; h < 5; h++)
  {
    for (int a = 0; a < 4; a++)
    {
      for (int p1 = 0; p1 < 3; p1++)
      {
        for (int p2 = 0; p2 < 2; p2++)
        {
          count++;
        }
      }
    }
  }

  cout << "count: " << count << endl;

  return 0;
}
