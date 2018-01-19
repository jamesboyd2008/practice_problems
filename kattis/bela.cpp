/*
This program calculates the total score in a card game.

This problem is from https://open.kattis.com/problems/bela

Name of Problem: Bela
Young Mirko is a smart, but mischievous boy who often wanders around parks looking for new ideas. This time he’s come across pensioners playing the card game Belote. They’ve invited him to help them determine the total number of points in a game.

Each card can be uniquely determined by its number and suit. A set of four cards is called a hand. At the beginning of a game one suit that “trumps” any other is chosen, and it is called the dominant suit. The number of points in a game is equal to the sum of values of each card from each hand in the game. Mirko has noticed that the pensioners have played N hands and that suit B was the dominant suit.

The value of each card depends on its number and whether its suit is dominant, and is given below:

Number         Value
          Dominant  Not_dominant
A         11        11
K         4         4
Q         3         3
J         20        2
T         10        10
9         14        0
8         0         0
7         0         0

Write a programme that will determine and output the number of points in the game.

Input
The first line contains the number of hands N (1≤N≤100) and the value of suit B (S, H, D, C) from the task. Each of the following 4N lines contains the description of a card (the first character is the number of the i-th card (A, K, Q, J, T, 9, 8, 7), and the second is the suit (S, H, D, C)).

Output
The first and only line of output must contain the number of points from the task.

Sample Input 1
2 S
TH
9C
KS
QS
JS
TD
AD
JH

Sample Output 1
60

Sample Input 2
4 H
AH
KH
QH
JH
TH
9H
8H
7H
AS
KS
QS
JS
TS
9S
8S
7S

Sample Output 2
92
*/

#include "iostream"
#include "array"
#include "map"

using namespace std;

int main()
{
  int hands, total = 0;
  char dominant, value, suit;

  map<char, array<int, 2>> values;
  values['A'][0] = 11;
  values['A'][1] = 11;
  values['K'][0] = 4;
  values['K'][1] = 4;
  values['Q'][0] = 3;
  values['Q'][1] = 3;
  values['J'][0] = 20;
  values['J'][1] = 2;
  values['T'][0] = 10;
  values['T'][1] = 10;
  values['9'][0] = 14;
  values['9'][1] = 0;
  values['8'][0] = 0;
  values['8'][1] = 0;
  values['7'][0] = 0;
  values['7'][1] = 0;

  cin >> hands >> dominant;

  for (int i = 0; i < 4 * hands; i++)
  {
    cin >> value >> suit;
    if (suit == dominant)
    {
      total += values[value][0];
    }
    else
    {
      total += values[value][1];
    }
  }

  cout << total << endl;

  return 0;
}
