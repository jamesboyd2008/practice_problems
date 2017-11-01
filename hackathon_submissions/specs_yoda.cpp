// test driver for yoda program

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#define toDigit(c) (c - '0')

using namespace std;

vector<string> yoda(string input1, string input2)
{
  string result1, result2;
  vector<int> compare1, compare2, survivors1, survivors2;
  int num, sum1 = 0, sum2 = 0, testNum = 0;

  for (int i = 0; i < input1.size(); i++)
  {
    compare1.push_back(toDigit(input1[i]));
  }


  for (int i = 0; i < input2.size(); i++)
  {
    compare2.push_back(toDigit(input2[i]));
  }


  // pad compares on front w/ zeros 'till they're the same size
  auto it1 = compare1.insert(compare1.begin(), 0);
  while (compare1.size() < compare2.size())
  {
    it1 = compare1.insert(it1, 0);
  }

  // pad compares on front w/ zeros 'till they're the same size
  auto it2 = compare2.insert(compare2.begin(), 0);
  while (compare2.size() < compare1.size())
  {
    it2 = compare2.insert(it2, 0);
  }


  // collide the nums!
  for (int i = 0; i < compare1.size(); i++)
  {
    if (compare1[i] > compare2[i])
    {
      survivors1.push_back(compare1[i]);
    }
    else if (compare2[i] > compare1[i])
    {
      survivors2.push_back(compare2[i]);
    }
    else // they're equal
    {
      survivors1.push_back(compare1[i]);
      survivors2.push_back(compare2[i]);
    }
  }


  for (int i = 0; i < survivors1.size(); i++)
  {
    sum1 += pow(10, survivors1.size() - 1 - i) * survivors1[i];
  }

  for (int i = 0; i < survivors2.size(); i++)
  {
    sum2 += pow(10, survivors2.size() - 1 - i) * survivors2[i];
  }

  // output result
  if (survivors1.size() == 1)
    result1 = "YODA";
  else
    result1 = to_string(sum1);

  if (survivors2.size() == 1)
    result2 = "YODA";
  else
    result2 = to_string(sum2);

  vector<string> answer = {result1, result2};
  return answer;
}

int main()
{
  vector< vector<string> > problems =
  {
    {"300", "500"},
    {"65743", "9651"},
    {"2341", "6785"},
    {"456328", "284315"},
    {"909090", "70707"},
    {"8675399", "1234288"},
    {"2000000000", "1000000000"},
    {"2345678", "1234567"},
    {"1", "1"},
    {"1000000000", "1000000000"},
    {"87004001", "96213890"}
  };

  vector< vector<string> > answers =
  {
    {"0", "500"},
    {"673", "95"},
    {"YODA", "6785"},
    {"46328", "83"},
    {"999", "777"},
    {"8675399", "YODA"},
    {"2000000000", "0"},
    {"2345678", "YODA"},
    {"1", "1"},
    {"1000000000", "1000000000"},
    {"741", "92189"}
  };

  int testNum = 0;
  vector<string> results;
  for (int i = 0; i < problems.size(); i++)
  {
    results = yoda(problems[i][0], problems[i][1]);
    if
    (
      results[0].compare(answers[i][0]) == 0 &&
      results[1].compare(answers[i][1]) == 0
    )
      cout << "test " << testNum << ": pass\n";
    else
      cout << "test " << testNum << ": fail\n";
    testNum++;
  }

  return 0;
}
