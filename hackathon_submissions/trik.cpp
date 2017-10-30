/*
Jealous of Mirko’s position as head of the village, Borko stormed into his tent and tried to demonstrate Mirko’s incompetence for leadership with a trick.

Borko puts three opaque cups onto the table next to each other (opening facing down) and a small ball under the leftmost cup. He then swaps two cups in one of three possible ways a number of times. Mirko has to tell which cup the ball ends up under.

A---> swaps contents of cups 1 & 2
B---> swaps contents of cups 2 & 3
C---> swaps contents of cups 1 & 3

Wise Mirko grins with his arms crossed while Borko struggles to move the cups faster and faster. What Borko does not know is that programmers in the back are recording all his moves and will use a simple program to determine where the ball is. Write that program.

Input
The first and only line contains a non-empty string of at most 5050 characters, Borko’s moves. Each of the characters is ‘A’, ‘B’ or ‘C’ (without quote marks).

Output
Output the index of the cup under which the ball is: 11 if it is under the left cup, 22 if it is under the middle cup or 33 if it is under the right cup.
*/

#include <iostream>

using namespace std;

int main()
{
  char letter[2];
  int position = 1;

  while (cin.get(letter, 2))
  {
    if      (letter[0] == 'A')
    {
      if      (position == 1) position = 2;
      else if (position == 2) position = 1;
    }
    else if (letter[0] == 'B')
    {
      if      (position == 2) position = 3;
      else if (position == 3) position = 2;
    }
    else // (letter[0] == 'C')
    {
      if      (position == 1) position = 3;
      else if (position == 3) position = 1;
    }
  }

  cout << position << "\n";

  return 0;
}
