/*
This program outputs various ways to arrange the stars on the US flag.

https://open.kattis.com/problems/stararrangements

Star Arrangements
The recent vote in Puerto Rico favoring United States statehood has made flag makers very excited. An updated flag with 5151 stars rather than the current one with 5050 would cause a huge jump in U.S. flag sales. The current pattern for 5050 stars is five rows of 66 stars, interlaced with four offset rows of 55 stars. The rows alternate until all stars are represented.
    * * * * * *
     * * * * *
    * * * * * *
     * * * * *
    * * * * * *
     * * * * *
    * * * * * *
     * * * * *
    * * * * * *
This pattern has the property that adjacent rows differ by no more than one star. We represent this star arrangement compactly by the number of stars in the first two rows: 6,5.

A 5151-star flag that has the same property can have three rows of 99 stars, interlaced with three rows of 88 stars (with a compact representation of 9,8). Conversely, if a state were to leave the union, one appealing representation would be seven rows of seven stars (7,7).

A flag pattern is visually appealing if it satisfies the following conditions:

Every other row has the same number of stars.
Adjacent rows differ by no more than one star.
The first row cannot have fewer stars than the second row.
Your team sees beyond the short-term change to 51 for the US flag. You want to corner the market on flags for any union of three or more states. Given the number S of stars to draw on a flag, find all possible visually appealing flag patterns.

Input
The input consists of a single line containing the integer S (3≤S≤32767).

Output
On the first line, print S, followed by a colon. Then, for each visually appealing flag of S stars, print its compact representation, one per line.

This list of compact representations should be printed in increasing order of the number of stars in the first row; if there are ties, print them in order of the number of stars in the second row. The cases 1-by-S and S-by-1 are trivial, so do not print those arrangements.

The compact representations must be printed in the form “x,y”, with exactly one comma between x and y and no other characters.

Sample Input 1
3
Sample Output 1
3:
2,1

Sample Input 2
50
Sample Output 2
50:
2,1
2,2
3,2
5,4
5,5
6,5
10,10
13,12
17,16
25,25

Sample Input 3
51
Sample Output 3
51:
2,1
3,3
9,8
17,17
26,25
*/

#include <iostream>

using namespace std;

int main()
{
  const char spades[4]   = "\u2660",
             hearts[4]   = "\u2665",
             diamonds[4] = "\u2666",
             clubs[4]    = "\u2663";

  cout << "spades: " << spades << endl;
  cout << "hearts: " << hearts << endl;
  cout << "diamonds: " << diamonds << endl;
  cout << "clubs: " << clubs << endl;

  return 0;
}
