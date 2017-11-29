/*
This program tells you whether a string contains two consecutive s's.

from https://open.kattis.com/problems/hissingmicrophone

Hissing Microphone
A known problem with some microphones is the “hissing s”. That is, sometimes the sound of the letter s is particularly pronounced; it stands out from the rest of the word in an unpleasant way.

Of particular annoyance are words that contain the letter s twice in a row. Words like amiss, kiss, mississippi and even hiss itself.

Input
The input contains a single string on a single line. This string consists of only lowercase letters (no spaces) and has between 11 and 3030 characters.

Output
Output a single line. If the input string contains two consecutive occurrences of the letter s, then output hiss. Otherwise, output no hiss.

Sample Input 1	Sample Output 1
amiss           hiss
Sample Input 2	Sample Output 2
octopuses       no hiss
Sample Input 3	Sample Output 3
hiss            hiss
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string word;
  cin >> word;

  bool last_letter_was_s = false,
                  two_ss = false;

  for (int i = 0; i < word.size(); i++)
  {
    if (word[i] == 's')
    {
      if (last_letter_was_s)
      {
        two_ss = true;
        break;
      }
      last_letter_was_s = true;
    }
    else
      last_letter_was_s = false;
  }

  if (two_ss)
    cout << "hiss\n";
  else
    cout << "no hiss\n";

  return 0;
}
