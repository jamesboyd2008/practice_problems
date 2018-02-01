/*
This programme, given a date in 2009, outputs that day of the week.

This problem is from https://open.kattis.com/problems/datum

Title: Datum
Write a program that, given a date in 2009, determines the day of week on that date.

Input
The first line contains two positive integers D (day) and M (month) separated by a space. The numbers will be a valid date in 2009.

Output
Output the day of the week on day D of month M in 2009. The output should be one of the words “Monday”, “Tuesday”, “Wednesday”, “Thursday”, “Friday”, “Saturday” or “Sunday”.

Sample Input 1	Sample Output 1
1 1             Thursday

Sample Input 2	Sample Output 2
17 1            Saturday

Sample Input 3	Sample Output 3
25 9            Friday
*/

#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
  // January 1, 2009 was a Thursday.
  vector<string> week_days =
  {
    "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"
  };
  vector<int> month_lengths =
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int day, month, days_passed = 0;

  cin >> day >> month;

  for (int i = 0; i < month - 1; i++)
  {
    days_passed += month_lengths[i];
  }
  days_passed += day - 1;

  cout << week_days[days_passed % 7] << endl;

  return 0;
}
