/*
Last night when you went to sleep, you had a strange feeling that you may
see the same day again. And your strange feeling came to bewhen you woke
up, everyone seemed to think that it was yesterday morning! The same
strange feeling came back in the evening.

When this pattern continued for days, you looked for help from a time
wizard. The wizard says he can break you out of the time loop, but you
must chant his spell. The wizard gives you a magic number, and you must
count up to that number, starting at 11, saying “Abracadabra” each time.
*/

#include <iostream>

using namespace std;

int main()
{
  int times;
  cin >> times;

  for (int i = 1; i <= times; i++)
  {
    cout << i << " Abracadabra\n";
  }

  return 0;
}
