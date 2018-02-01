/*
This program finds a number, the sum of whose digits equals a specific value,
that fits between two other numbers.

This problem is from https://open.kattis.com/problems/zamka

Title: Zamka
The impossible has happened. Bear G. has fallen into his own trap. Lured by a
delicious box of Domaćica, without even thinking, he rushed and fell into his
trap. In order to get out of the trap, he must solve the following task with
your help. You are given three integers L, D and X.

determine the minimal integer N such that L≤N≤D and the sum of its digits is X

determine the maximal integer M such that L≤M≤D and the sum of its digits is X

Bear will be able to escape from the trap if he correctly determines numbers
N and M. The numbers N and M will always exist.

Input
The first line of input contains the integer L (1≤L≤10000), the number from
the task. The second line of input contains the integer D (1≤D≤10000, L≤D), the
number from the task. The third line of input contains the integer X (1≤X≤36),
the number from the task.

Output
The first line of output must contain the integer N from the task. The second
line of output must contain the integer M from the task.

Sample Input 1
1
100
4

Sample Output 1
4
40

Sample Input 2
100
500
12

Sample Output 2
129
480

Sample Input 3
1
10000
1
Sample Output 3
1
10000
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int low, high, sum, digits_sum = 0;
  vector<int> answers;

  cin >> low >> high >> sum;

  for (int i = low; i <= high; i++)
  {
    string digits = to_string(i);

    for (int j = 0; j < digits.size(); j++)
    {
      int num = (int)(digits[j]) - 48;
      digits_sum += num;
    }
    if (digits_sum == sum)
      answers.push_back(i);

    digits_sum = 0;
  }

  cout << answers.front() << endl << answers.back() << endl;

  return 0;
}
