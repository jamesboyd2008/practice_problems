/*
This program, given a sequence of battle moves, outputs the quantity of battles
won.

This problem is from https://open.kattis.com/problems/deathknight

Title: Death Knight Hero
There once was a champion of WoW
Arthasdk the name he was bestowed
He Death Gripped you to his side
His Chains of Ice stopped your stride
And Obliterates made you say “OWW!”

But one day our hero got puzzled
His Death Grip totally fizzled
In his darkest despair
He could barely hear
“OMG NOOB u Chains of Iced than u Death Gripped”

Input
You are given a recording of the abilities our hero used in his battles.

The first line of input will contain a single integer nn (1≤n≤100), the number of battles our hero played.

Then follow nn lines each with a sequence of kiki (1≤ki≤1000) characters, each of which are either ’C’, ’D’ or ’O’. These denote the sequence of abilities used by our hero in the i-th battle. ’C’ is Chains of Ice, ’D’ is Death Grip and ’O’ is Obliterate.

Output
Output the number of battles our hero won, assuming he won each battle where he did not use Chains of Ice immediately followed by Death Grip.

Sample Input 1	Sample Output 1
3               2
DCOOO
DODOCD
COD
*/

#include "iostream"
#include "string"

using namespace std;

int main()
{
  int battles, fails = 0;
  string moves;

  cin >> battles;
  for (int i = 0; i < battles; i++)
  {
    cin >> moves;

    for (int j = 0; j < moves.size(); j++)
    {
      if (moves[j] == 'C' && moves[j + 1] == 'D')
      {
        fails++;
      }
    }
  }

  cout << battles - fails << endl;

  return 0;
}
