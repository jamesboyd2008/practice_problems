/*
This program tells a user whether to advertise.

from https://open.kattis.com/problems/nastyhacks

Nasty Hacks
You are the CEO of Nasty Hacks Inc., a company that creates small pieces of malicious software which teenagers may use to fool their friends. The company has just finished their first product and it is time to sell it. You want to make as much money as possible and consider advertising in order to increase sales. You get an analyst to predict the expected revenue, both with and without advertising. You now want to make a decision as to whether you should advertise or not, given the expected revenues.
Input
The input consists of nn cases, and the first line consists of one positive integer giving nn. The next nn lines each contain 3 integers, r, e and c. The first, r, is the expected revenue if you do not advertise, the second, e, is the expected revenue if you do advertise, and the third, c, is the cost of advertising. You can assume that the input will follow these restrictions: 1≤n≤100, −10^6≤r,e≤10^6, and 0≤c≤10^6.

Output
Output one line for each test case: “advertise”, “do not advertise” or “does not matter”, indicating whether it is most profitable to advertise or not, or whether it does not make any difference.

Sample Input 1
3
0 100 70
100 130 30
-100 -70 40

Sample Output 1
advertise
does not matter
do not advertise
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int yes_ad, no_ad, ad_cost, n, profit_margin;
  vector<string> outcomes;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> no_ad >> yes_ad >> ad_cost;
    profit_margin = yes_ad - ad_cost;

    if (profit_margin > no_ad)
      outcomes.push_back("advertise");
    else if (profit_margin < no_ad)
      outcomes.push_back("do not advertise");
    else
      outcomes.push_back("does not matter");
  }

  for (int i = 0; i < outcomes.size(); i++)
    cout << outcomes[i] << endl;

  return 0;
}
