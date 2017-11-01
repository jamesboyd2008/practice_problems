/*
Problem from https://open.kattis.com/problems/yoda

A long, long time ago in a galaxy far, far away a big collision of integers is taking place right now. What happens when two integers collide? During collision, each digit of one number compares itself to the corresponding digit of the other number (the least significant digit with the other’s least significant digit, and so on). The smaller digit “falls out” of the number containing it. Additionally, if the digits are the same, nothing happens. If a number doesn’t consist of a corresponding digit, then we consider it to be zero. After all comparisons of corresponding digits, the leftover digits in the number come closer and create a new number. See Figure 1 for an example.

456328 -> 4 6328 -> 46328
284315 ->  8 3   ->    83
Figure 1: Collision example

Write a programme that will, for two given integers, determine their values after collision. If it happens that all the digits of one number fell out, then for that number output the message “YODA”.

Input
The first line of input contains the integer NN (1≤N≤1091≤N≤109), one of the integers from the task. The second line of input contains the integer MM (1≤N≤1091≤N≤109), one of the integers from the task.

Output
The first line of output must contain the new value of the first given integer from the task. The second line of output must contain the new value of the second given integer from the task.

Sample Input 1
300
500
Sample Output 1
0
500

Sample Input 2
65743
9651
Sample Output 2
673
95

Sample Input 3
2341
6785
Sample Output 3
YODA
6785
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#define toDigit(c) (c - '0')

using namespace std;

int main()
{
  string input1, input2, result1, result2;
  vector<int> compare1, compare2;
  vector<int> survivors1, survivors2;
  int num, sum1 = 0, sum2 = 0;

  cin >> input1 >> input2;
  // cout << input1 << endl << input2 << endl;

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

  cout << result1 << endl;
  cout << result2 << endl;

  return 0;
}
