/*
This program, given moose antler data, produces more communicable
antler data.
https://open.kattis.com/problems/judgingmoose
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int tines1, tines2;
  string result;
  cin >> tines1 >> tines2;

  if (tines1 > tines2)
  {
    result += "Odd " + to_string(tines1 * 2);
  }
  else if (tines2 > tines1)
  {
    result += "Odd " + to_string(tines2 * 2);
  }
  else if (tines1 > 0)
  {
    result += "Even " + to_string(tines1 * 2);
  }
  else
    result += "Not a moose";

  cout << result << endl;

  return 0;
}
