/*
https://open.kattis.com/problems/quadrant
A common problem in mathematics is to determine which quadrant a given point lies in. There are four quadrants, numbered from 11 to 44, as shown in the diagram below:

     |
 2   |   1
     |
------------
     |
 3   |   4
     |

For example, the point AA, which is at coordinates (12,5)(12,5) lies in quadrant 11 since both its xx and yy values are positive, and point BB lies in quadrant 2 since its xx value is negative and its yy value is positive.

Your job is to take a point and determine the quadrant it is in. You can assume that neither of the two coordinates will be 00.

Input
The first line of input contains the integer xx (−1000≤x≤1000;x≠0−1000≤x≤1000;x≠0). The second line of input contains the integer yy (−1000≤y≤1000;y≠0−1000≤y≤1000;y≠0).

Output
Output the quadrant number (1, 2, 3 or 4) for the point (x,y).

Sample Input 1
10
6
Sample Output 1
1

Sample Input 2
9
-13
Sample Output 2
4
*/

#include <iostream>

using namespace std;

int main()
{
  string num1, num2;
  cin >> num1 >> num2;

  if (num1[0] == '-')
  {
    if (num2[0] == '-')
    {
      cout << 3 << endl;
    }
    else
      cout << 2 << endl;
  }
  else if (num2[0] == '-')
  {
    cout << 4 << endl;
  }
  else
    cout << 1 << endl;

  return 0;
}
