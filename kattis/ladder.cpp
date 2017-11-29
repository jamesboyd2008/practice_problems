/*
This program calculates the required height of a ladder.

from https://open.kattis.com/problems/ladder

Ladder
You are attempting to climb up the roof to fix some leaks, and have to go buy a ladder. The ladder needs to reach to the top of the wall, which is hh centimeters high, and in order to be steady enough for you to climb it, the ladder can be at an angle of at most vv degrees from the ground. How long does the ladder have to be?

Input
The input consists of a single line containing two integers hh and vv, with meanings as described above. You may assume that 1≤h≤10000 and that 1≤v≤89.

Output
Write a single line containing the minimum possible length of the ladder in centimeters, rounded up to the nearest integer.

Sample Input 1	Sample Output 1
500 70          533

Sample Input 2	Sample Output 2
1000 10         5759
*/

#include <iostream>
#include <cmath>

using namespace std;

static double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
}

int main()
{
  double height, angle, ladder;

  cin >> height >> angle;

  cout << ceil( height / sin( d2r(angle) ) ) << endl;

  return 0;
}
