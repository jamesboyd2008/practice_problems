// This program simulates a pedometer.
#include "meter.h"

int main()
{
  cout << "You just ate a Big Mac. Attempt to burn off those 560 \n"
  << "Calories by taking 1400 steps to walk around Liliuokalani \n" << "Gardens. It takes you 36 steps to burn 1 Calorie.\n\n";

  Pedometer meter;
  cin >> meter;
  cout << meter;

  string response = "y";
  int steps;

  while ((meter.getCalories() < 560) && (response == "y"))
  {
    cout << "Would you like to keep going? y/n: ";
    cin >> response;
    if (response == "n")
    {
      meter.reset();
    } else {
      cout << "How many more steps have you taken? ";
      cin >> steps;
      meter.increment(steps);
      cout << meter;
    }
  }
}
