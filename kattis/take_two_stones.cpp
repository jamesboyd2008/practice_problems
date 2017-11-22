/*
This program predicts the outcome of a game.

Take Two Stones
Alice and Bob are playing a new game of stones. There are NN stones placed on the ground, forming a sequence. The stones are labeled from 11 to NN. Alice and Bob in turns take exactly two consecutive stones on the ground until there are no consecutive stones on the ground. That is, each player can take stone i and stone i+1, where 1≤i≤N−1. If the number of stone left is odd, Alice wins. Otherwise, Bob wins.
Assume both Alice and Bob play optimally and Alice plays first, do you know who the winner is?

Input
The input contains an integer NN (1≤N≤10000000)(1≤N≤10000000), the number of stones.

Output
Output the winner, “Alice” or “Bob” (without the quotes), on a line.

https://open.kattis.com/problems/twostones
*/

#include <iostream>

using namespace std;

int main()
{
  int stones;
  cin >> stones;

  if (stones % 2 == 0)
    cout << "Bob\n";
  else
    cout << "Alice\n";

  return 0;
}
