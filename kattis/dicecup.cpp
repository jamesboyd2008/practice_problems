/*
This program outputs the most likely dice roll, given some dice data.

This problem is from https://open.kattis.com/problems/dicecup

Title: Dice Cup
In many table-top games it is common to use different dice to simulate random events. A “d” or “D” is used to indicate a die with a specific number of faces, d4 indicating a four-sided die, for example. If several dice of the same type are to be rolled, this is indicated by a leading number specifying the number of dice. Hence, 2d6 means the player should roll two six-sided dice and sum the result face values.

Task
Write a program to compute the most likely outcomes for the sum of two dice rolls. Assume each die has numbered faces starting at 1 and that each face has equal roll probability.

Input
The input consists of a single line with two integer numbers, N,M, specifying the number of faces of the two dice.

Constraints
4≤N,M≤20 Number of faces.

Output
A line with the most likely outcome for the sum; in case of several outcomes with the same probability, they must be listed from lowest to highest value in separate lines.

Sample Input 1
6 6

Sample Output 1
7

Sample Input 2
6 4

Sample Output 2
5
6
7

Sample Input 3
12 20

Sample Output 3
13
14
15
16
17
18
19
20
21
*/

#include "iostream"
#include "vector"

using namespace std;

bool increasing (int one, int two)
{
  return (one < two);
}

int main()
{
  int die_1, die_2;
  cin >> die_1 >> die_2;
  vector<int> values;
  vector<int> likeliest_rolls;

  for (int i = 1; i <= die_1; i++)
  {
    for (int j = 1; j <= die_2; j++)
    {
      values.push_back(i + j);
    }
  }

  sort(values.begin(), values.end(), increasing);

  int max_occurences = 0;
  int current_count = 0;
  for (int i = 0; i < values.size(); i++)
  {
    current_count = 0;
    for (int j = 0; j < values.size(); j++)
    {
      if (values[j] == values[i])
      {
        current_count++;
        if (current_count > max_occurences)
        {
          max_occurences = current_count;
        }
      }
    }
  }

  bool got_one = false;
  for (int i = 0; i < values.size(); i++)
  {
    int current_count = 0;
    if (!got_one)
    {
      for (int j = 0; j < values.size(); j++)
      {
        if (values[j] == values[i])
        {
          current_count++;
          if (current_count == max_occurences)
          {
            likeliest_rolls.push_back(values[i]);
            got_one = true;
            break;
          }
        }
      }
    }
    else
    {
      i += max_occurences - 2;
      got_one = false;
    }
    current_count = 0;
  }

  for (int i = 0; i < likeliest_rolls.size(); i++)
  {
    cout << likeliest_rolls[i] << endl;
  }

  return 0;
}
