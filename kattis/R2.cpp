/*
R2
The number SS is called the mean of two numbers R1R1 and R2R2 if SS is equal to (R1+R2)/2(R1+R2)/2. Mirko’s birthday present for Slavko was two integers R1R1 and R2R2. Slavko promptly calculated their mean which also happened to be an integer but then lost R2R2! Help Slavko restore R2R2.

Input
The first and only line of input contains two integers R1R1 and SS, both between −1000−1000 and 10001000.

Output
Output R2R2 on a single line.
*/

#include <iostream>

using namespace std;

int main()
{
  int r1, s;
  cin >> r1 >> s;
  cout << 2 * s - r1 << endl;

  return 0;
}
