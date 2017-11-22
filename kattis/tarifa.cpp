/*
This program caluclate remaining rolover data for a cable plan.
https://open.kattis.com/problems/tarifa
*/

#include <iostream>

using namespace std;

int main()
{
  int mb_per_month, months, rollover_mb = 0, consumed_mb;

  cin >> mb_per_month;
  cin >> months;

  for (int i = 0; i < months; i++)
  {
    rollover_mb += mb_per_month;
    cin >> consumed_mb;
    rollover_mb -= consumed_mb;
  }
  rollover_mb += mb_per_month;

  cout << rollover_mb << endl;

  return 0;
}
