/*
This program outputs card suites.
*/

#include <iostream>

using namespace std;

int main()
{
  const char spades[4]   = "\u2664",
             hearts[4]   = "\u2661",
             diamonds[4] = "\u2662",
             clubs[4]    = "\u2667";

  cout << "spades: " << spades << endl;
  cout << "hearts: " << hearts << endl;
  cout << "diamonds: " << diamonds << endl;
  cout << "clubs: " << clubs << endl;

  return 0;
}
