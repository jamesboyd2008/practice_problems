#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Returns an integer.
 * This function receives a meal cost, tip percentage, and tax
 * percentage from the command line.  It then prints the total cost
 * of the meal, rounded to the nearest integer, to the
 * command line.
 */
int main()
{
  float meal_cost, tip_percent, tax_percent, total_tip,
    total_tax, total_cost;

  cin >> meal_cost;
  cin >> tip_percent;
  cin >> tax_percent;

  total_tip = meal_cost * tip_percent / 100;
  total_tax = meal_cost * tax_percent / 100;
  total_cost = meal_cost + total_tip + total_tax;

  cout << "The total meal cost is " << round(total_cost) << " dollars."
       << endl;

  return 0;
}
