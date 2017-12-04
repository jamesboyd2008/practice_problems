/*
This program outputs the result of formula.

from https://open.kattis.com/problems/pot

Pot
The teacher has sent an e-mail to her students with the following task: “Write a program that will determine and output the value of XX if given the statement:
X=baseber1pow1+baseber2pow2+…+baseberNpowN
and it holds that baseber1baseber1, baseber2baseber2 to baseberNbaseberN are integers, and pow1pow1, pow2pow2 to powNpowN are one-digit integers.” Unfortunately, when the teacher downloaded the task to her computer, the text formatting was lost so the task transformed into a sum of NN integers:
X=P1+P2+…+PN
For example, without text formatting, the original task in the form of X=21^2+125^3 became a task in the form of X=212+1253. Help the teacher by writing a program that will, for given N integers from P1 to PN determine and output the value of X from the original task.

Input
The first line of input contains the integer NN (1≤N≤10), the baseber of the addends from the task. Each of the following NN lines contains the integer PiPi (10≤Pi≤9999, i=1,…,Ni=1,…,N) from the task.

Output
The first and only line of output must contain the value of X (X≤1000000000) from the original task.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int count, base, exponent, sum = 0;
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cin >> base;
    exponent = base - (base / 10) * 10;
    base /= 10;
    sum += pow(base, exponent);
  }

  cout << sum << endl;

  return 0;
}
