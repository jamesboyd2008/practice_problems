/**
 *  This program calculates someone's pay, given a pay rate and hours worked.
 */
#include <iostream>

using namespace std;

// Calculates someone's pay. Asks user for two input variables.
int main()
{
  double hours, rate, payout;

  cout << "How many hours did you work? ";
  cin >> hours;

  cout << "How much do you get paid per hour? ";
  cin >> rate;

  payout = hours * rate;

  cout << "You've earned " << payout << " dollars.\n";
}
