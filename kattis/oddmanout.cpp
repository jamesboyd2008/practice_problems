/*
This program tells you which one of these things is not like the other.

from https://open.kattis.com/problems/oddmanout

Odd Man Out
You are hosting a party with G guests and notice that there is an odd number of guests! When planning the party you deliberately invited only couples and gave each couple a unique number C on their invitation. You would like to single out whoever came alone by asking all of the guests for their invitation numbers.

Input
The first line of input gives the number of cases, N. N test cases follow. For each test case there will be:

One line containing the value G the number of guests.

One line containing a space-separated list of G integers. Each integer C indicates the invitation code of a guest.

You may assume that 1≤N≤50,0<C<2^31,3≤G<1000.

Output
For each test case, output one line containing “Case #x: ” followed by the number C of the guest who is alone.

Sample Input 1
3
3
1 2147483647 2147483647
5
3 4 7 4 3
5
2 10 2 10 5

Sample Output 1
Case #1: 1
Case #2: 7
Case #3: 5
*/

#include "iostream"
#include "vector"

using namespace std;

int main()
{
  vector<int> winners;
  vector<int> guests;
  int parties, guest_count, id;

  cin >> parties;
  for (int i = 0; i < parties; i++)
  {
    cin >> guest_count;
    for (int j = 0; j < guest_count; j++)
    {
      cin >> id;
      guests.push_back(id);
    }

  int loner;
  bool found;
  for (int k = 0; k < guests.size(); k++)
  {
    loner = guests[k];
    for (int l = 0; l < guests.size(); l++)
    {
      if (loner == guests[l] && k != l)
        break;
      if (l == guests.size() - 1)
      {
        found = true;
        winners.push_back(loner);
      }
    }
    if (found)
      break;
  }
    guests = {};
    found = false;
  }

  for (int w = 0; w < winners.size(); w++)
  {
    cout << "Case #" << w + 1 << ": " << winners[w] << endl;
  }

  return 0;
}
