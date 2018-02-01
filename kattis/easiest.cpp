/*
This program, given an integer, N, outputs the smallest integer, p,  such that
N⋅p has the same sum of digits as N and p is bigger than 10.

This problem if from https://open.kattis.com/problems/easiest

Title: The Easiest Problem Is This One
Some people think this is the easiest problem in today’s problem set. Some people think otherwise, since it involves sums of digits of numbers and that’s difficult to grasp.

If we multiply a number NN with another number mm, the sum of digits typically changes. For example, if m=26 and N=3029, then N⋅m=78754 and the sum of the digits is 31, while the sum of digits of N is 14.

However, there are some numbers that if multiplied by NN will result in the same sum of digits as the original number N. For example, consider m=37,N=3029, then N⋅m=112073, which has sum of digits 14, same as the sum of digits of N.

The task is to find the smallest positive integer p among those that will result in the same sum of the digits when multiplied by N. To make the task a little bit more challenging, the number must also be higher than ten.

Input
The input consists of several test cases. Each case is described by a single line containing one positive integer number N,1≤N≤100000. The last test case is followed by a line containing zero.

Output
For each test case, print one line with a single integer number p which is the minimal number such that N⋅p has the same sum of digits as N and p is bigger than 10.

Sample Input 1	Sample Output 1
3029            37
4               28
5               28
42              25
0
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// returns the sum of the digits of the single integer argument
int digitSum(int num)
{
  string numStr = to_string(num);
  int sum = 0;
  for (int i = 0; i < numStr.size(); i++)
  {
    sum += (int)numStr[i] - '0';
  }
  return sum;
}

int main()
{
  bool keepGoing = true;
  vector<int>results;
  while (keepGoing)
  {
    int input, output;
    cin >> input;
    if (input == 0)
    {
      keepGoing = false;
      break;
    }
    int inputSum = digitSum(input);

    bool foundIt = false;
    int i = 11;
    while (!foundIt) // might run too long ...
    {
      int product = i * input;
      int productSum = digitSum(product);

      if (productSum == inputSum)
      {
        output = i;
        foundIt = true;
      }
      i++;
    }

    results.push_back(output);
  }

  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }

  return 0;
}
