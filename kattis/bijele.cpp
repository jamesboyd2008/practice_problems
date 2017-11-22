/*
This program, given chess piece data, outputs the difference between
how many pieces are provided and how many are needed.
https://open.kattis.com/problems/bijele
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int quantity;
  vector<int> the_norm = { 1, 1, 2, 2, 2, 8 };

  for (int i = 0; i < 6; i++)
  {
    cin >> quantity;
    cout << to_string(the_norm[i] - quantity) << ' ';
  }
  cout << "\n";

  return 0;
}
