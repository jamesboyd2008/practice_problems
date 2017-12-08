/*
This program prints the integer corresponding to the reverse binary expression
of the input integer.

from https://open.kattis.com/problems/reversebinary

Reversed Binary Numbers
Yi has moved to Sweden and now goes to school here. The first years of schooling she got in China, and the curricula do not match completely in the two countries. Yi likes mathematics, but now... The teacher explains the algorithm for subtraction on the board, and Yi is bored. Maybe it is possible to perform the same calculations on the numbers corresponding to the reversed binary representations of the numbers on the board? Yi dreams away and starts constructing a program that reverses the binary representation, in her mind. As soon as the lecture ends, she will go home and write it on her computer.

Task
Your task will be to write a program for reversing numbers in binary. For instance, the binary representation of 13 is 1101, and reversing it gives 1011, which corresponds to number 11.

Input
The input contains a single line with an integer N, 1≤N≤1000000000.

Output
Output one line with one integer, the number we get by reversing the binary representation of N.

=======================================
Sample Input 1
13

Sample Output 1
11
=======================================

=======================================
Sample Input 2
47

Sample Output 2
61
=======================================

*/

#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

// converts a binary to a decimal
// takes a string argument, a binary num greater than or equal to 0.
int binary_to_decimal(string zero_one_zero)
{
  int result = 0;

  int two_to_n = 1; // n initially equals zero, then 1, then 2...

  for (int i = zero_one_zero.size() - 1; i >= 0; i--)
  {
    if (zero_one_zero[i] == '1')
      result += two_to_n; // * zero_one_zero[i]

    two_to_n *= 2;
  }

  return result;
}

int main()
{
  int input;
  cin >> input;

  // 1,000,000,000 in binary is 30 bits long
  // 31 ensures the first char is zero for the erase call.
  bitset<31> bitsy(input);

  string zeros = bitsy.to_string();

  int i = 0;
  while (zeros[i] != '1')
    i++;

  zeros.erase(0, i);
  reverse(zeros.begin(), zeros.end());
  cout << binary_to_decimal(zeros) << endl;

  return 0;
}
