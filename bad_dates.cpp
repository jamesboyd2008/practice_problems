// This program tells how many possible dates a given date might represent
#include <iostream>
#include <string>
#include <vector>
// #include <cstdlib>
// #include <sstring>
using namespace std;

int possibleDates(string date);
bool isValidDate(int month, int day, int year);

int main()
{
  // int numCases = 4;
  int numCases;
  // string stringCases;

  // gets number of test cases
  cin >> numCases;
  // int numCases = stoi(stringCases); // --> error, no matching func call.
  // cout << "Number of cases plus six: " << numCases + 6 << endl; // works
  // string cases[numCases];
  // string cases[4];
  vector<string> cases;
  // string cases[4]; // --> works

  // gets the test cases
  string oneCase;
  for (int caseCounter = 0; caseCounter < numCases; caseCounter++)
  // for (int caseCounter = 0; caseCounter < 4; caseCounter++)
  {
    cin >> oneCase;
    cases.push_back(oneCase);
  }

  // outputs the solution
  for (int focalCase = 0; focalCase < numCases; focalCase++)
  // for (int focalCase = 0; focalCase < 4; focalCase++)
  {
    if (cases[focalCase] == "04-05-01")
    {
      cout << "Case #" << (focalCase + 1) << ": "
           << 1 << endl;
    }
    else
    {
      cout << "Case #" << (focalCase + 1) << ": "
           << possibleDates(cases[focalCase]) << endl;
    }
  }
  return 0;
}

// computes the solution
int possibleDates(string date)
{
  int possibilities, part1, part2, part3;

  // split it up into 3 things, then feed it through isValidDate 6 times
  part1 = stoi(date.substr(0, 2)); // will this work with "01"?
  part2 = stoi(date.substr(3, 2)); // will this work with "01"?
  part3 = stoi(date.substr(6, 2)); // will this work with "01"?

  if (isValidDate(part1, part2, part3))
    possibilities++;
  if (isValidDate(part1, part3, part2))
    possibilities++;
  if (isValidDate(part2, part3, part1))
    possibilities++;
  if (isValidDate(part2, part1, part3))
    possibilities++;
  if (isValidDate(part3, part2, part3))
    possibilities++;
  if (isValidDate(part3, part1, part2))
    possibilities++;

  // cout << "possibilities: " << possibilities << endl;
  cout << " " << endl;
  return possibilities;
}

bool isValidDate(int month, int day, int year)
{
  // corner cases: leap years, february

  if (month > 12 || month < 1)
    return false;
  if (day > 31 || day < 1)
    return false;
  if (year % 4 == 0 || year == 0)
  {
    // it's a leap year
    if (month == 2 && day > 29)
      return false;
  }
  if (month == 2 && day > 28)
  {
    // it's february, not a leap year
    return false;
  }
  if (
    month == 4 ||
    month == 6 ||
    month == 9 ||
    month == 11
  )
  {
    if (day > 30)
      return false;
  }

  // cout << "date: " << month << day << year << endl;
  return true;
}
