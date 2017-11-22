/*
This program tells the user how many scientists they need to bribe.
from https://open.kattis.com/problems/faktor
*/

#include <iostream>

using namespace std;

int main()
{
  int articles, impact_factor, bribes;
  cin >> articles >> impact_factor;

  bribes = articles * (impact_factor - 1) + 1;

  cout << bribes << endl;

  return 0;
}
