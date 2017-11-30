/*
This program outputs card suites.
*/

#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
  const char spades[4]   = "\u2664",
             hearts[4]   = "\u2661",
             diamonds[4] = "\u2662",
             clubs[4]    = "\u2667";

  Card card_zero;
  cout << card_zero << endl;

  return 0;
}
