/*
This program, given temperature data, outputs the number of days when
the temperature was less than zero.
https://open.kattis.com/problems/cold
*/

#include <iostream>

using namespace std;

int main()
{
  int num_days, temp, count = 0;
  cin >> num_days;

  for (int i = 0; i < num_days; i++)
  {
    cin >> temp;
    if (temp < 0)
      count++;
  }

  cout << count << "\n";

  return 0;
}
