// test driver for yoda program

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
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
  while (compare1.size() < compare2.size() + 1)
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
    {"87004001", "96213890"},
    {"0", "1"},
    {"1", "0"},
    {"1", "2"},
    {"2", "1"},
    {"2", "3"},
    {"3", "2"},
    {"3", "4"},
    {"4", "3"},
    {"4", "5"},
    {"5", "4"},
    {"5", "6"},
    {"6", "5"},
    {"6", "7"},
    {"7", "6"},
    {"7", "8"},
    {"8", "7"},
    {"8", "9"},
    {"9", "8"},
    {"1", "10"},
    {"1", "20"},
    {"1", "30"},
    {"1", "40"},
    {"1", "50"},
    {"1", "60"},
    {"1", "70"},
    {"1", "80"},
    {"1", "90"},
    {"1", "100"},
    {"20", "1"}
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
    {"741", "92189"},
    {"YODA", "1"},
    {"1", "YODA"},
    {"YODA", "2"},
    {"2", "YODA"},
    {"YODA", "3"},
    {"3", "YODA"},
    {"YODA", "4"},
    {"4", "YODA"},
    {"YODA", "5"},
    {"5", "YODA"},
    {"YODA", "6"},
    {"6", "YODA"},
    {"YODA", "7"},
    {"7", "YODA"},
    {"YODA", "8"},
    {"8", "YODA"},
    {"YODA", "9"},
    {"9", "YODA"},
    {"1", "1"},
    {"1", "2"},
    {"1", "3"},
    {"1", "4"},
    {"1", "5"},
    {"1", "6"},
    {"1", "7"},
    {"1", "8"},
    {"1", "9"},
    {"1", "10"},
    {"2", "1"}
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
    {
      cout << "test " << testNum << ": fail\n";
      cout << "  m: " << problems[i][0] << "   you said: " << results[0] << endl;
      cout << "  n: " << problems[i][1] << "  you said: " << results[1] << endl;
    }
    testNum++;
  }

  testNum = 0;

  // ofstream ofile;
  // ofile.open("delete_me_yoda.txt");
  // // test everything  m = 0...99, n = 0...99 (10,000 test cases)
  // ofile << "m      output line 1\nn      output line 2\n\n";
  // for (int m = 0; m < 100; m++)
  // {
  //   for (int n = 0; n < 100; n++)
  //   {
  //     // write test cases to a file
  //     // write the solutions to those test cases in the same file
  //     // spot check the answers manually? ==> the bug was id'd, thusly
  //     results = yoda(to_string(m), to_string(n));
  //     ofile << left << setw(7) << to_string(m)
  //           << right << setw(7) << results[0] << endl
  //           << left << setw(7) << to_string(n)
  //           << right << setw(7) << results[1] << "\n\n";
  //
  //     testNum++;
  //   }
  // }
  // ofile << "Quantity of test cases - 29: " << testNum << endl;
  // ofile.close();

  return 0;
}
