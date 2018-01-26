/*
This program, given a caloric requirement, outputs the number of soylent
bottles to consume.

This problem is from https://open.kattis.com/problems/soylent

Title: Soylent
Yraglac recently decided to try out Soylent, a meal replacement drink designed
to meet all nutritional requirements for an average adult. Soylent not only
tastes great but is also low-cost, which is important for Yraglac as he is
currently on a budget. Each bottle provides 400 calories, so it is recommended
that an individual should consume 5 bottles a day for 2000 total calories.
However, Yraglac is wondering how many bottles he should consume if his daily
calorie requirement is not the same as an average adult. He can only consume an
integer number of bottles, and needs to consume at least his daily calorie
requirement.

Input
The first line contains a single integer T≤1000 giving the number of test
cases. Each test case consists of a single line with an integer N (0≤N≤10000),
the number of calories Yraglac needs in a day.

Output
For each test case, output a single line containing the number of bottles
Yraglac needs to consume for the day.

Sample Input 1
2
2000
1600

Sample Output 1
5
4
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int cases, calories;
  cin >> cases;
  vector<int> bottles;

  for (int i = 0; i < cases; i++)
  {
    cin >> calories;
    int todays = ceil((double) calories / 400.0);
    bottles.push_back(todays);
  }

  for (int i = 0; i < cases; i++)
  {
    cout << bottles[i] << endl;
  }

  return 0;
}
