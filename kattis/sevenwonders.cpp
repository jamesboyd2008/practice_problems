/*
This program calculates a player's points for the card game, Seven Wonders.

from https://open.kattis.com/problems/sevenwonders

Seven Wonders
Seven Wonders is a card drafting game in which players build structures to earn points. The player who ends with the most points wins. One winning strategy is to focus on building scientific structures. There are three types of scientific structure cards: Tablet (‘T’), Compass (‘C’), and Gear (‘G’). For each type of cards, a player earns a number of points that is equal to the squared number of that type of cards played. Additionally, for each set of three different scientific cards, a player scores 7 points.
For example, if a player plays 3 Tablet cards, 2 Compass cards and 1 Gear card, she gets 3^2+2^2+1^2+7=21 points.

It might be tedious to calculate how many scientific points a player gets by the end of each game. Therefore, you are here to help write a program for the calculation to save everyone’s time.

Input
The input has a single string with no more than 50 characters. The string contains only letters ‘T’, ‘C’ or ‘G’, which denote the scientific cards a player has played in a Seven Wonders game.

Output
Output the number of scientific points the player earns.


Sample Input 1
TCGTTC

Sample Output 1
21

Sample Input 2
CCC

Sample Output 2
9

Sample Input 3
TTCCGG

Sample Output 3
26
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string input;
  cin >> input;

  int t, c, g, pairs_o_3, t_trio, c_trio, g_trio, result;
  t=c=g=pairs_o_3=t_trio=c_trio=g_trio=result=0;

  for (int i = 0; i < input.size(); i++)
  {
    // increment tcg
    char letter = input[i];

    if (letter == 'T')
    {
      t++;
      t_trio++;
    }
    else if (letter == 'C')
    {
      c++;
      c_trio++;
    }
    else // letter == 'G'
    {
      g++;
      g_trio++;
    }

    if
    (
      t_trio > 0 &&
      c_trio > 0 &&
      g_trio > 0
    )
    {
      result += 7;
      t_trio--;
      c_trio--;
      g_trio--;
    }
  }

  // square and sum tcg
  result += pow(t, 2);
  result += pow(c, 2);
  result += pow(g, 2);

  cout << result << endl;

  return 0;
}
