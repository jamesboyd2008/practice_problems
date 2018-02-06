/*
This program, given a list of names, outputs a reformatted list of names.

This puzzle is from https://open.kattis.com/problems/symmetricorder

Title: Symmetric Order
In your job at Albatross Circus Management (yes, it’s run by a bunch of clowns), you have just finished writing a program whose output is a list of names in nondescending order by length (so that each name is at least as long as the one preceding it). However, your boss does not like the way the output looks, and instead wants the output to appear more symmetric, with the shorter strings at the top and bottom and the longer strings in the middle. His rule is that each pair of names belongs on opposite ends of the list, and the first name in the pair is always in the top part of the list. In the first example set below, Bo and Pat are the first pair, Jean and Kevin the second pair, etc.

Input
The input consists of one or more sets of strings, followed by a final line containing only the value 0. Each set starts with a line containing an integer, n, which is the number of strings in the set, followed by nn strings, one per line, sorted in nondescending order by length. None of the strings contain spaces. There is at least one and no more than 15 strings per set. Each string is at most 25 characters long.

Output
For each input set print “SET n” on a line, where n starts at 1, followed by the output set as shown in the sample output.

Sample Input 1	   Sample Output 1
7                  SET 1
Bo                 Bo
Pat                Jean
Jean               Claude
Kevin              Marybeth
Claude             William
William            Kevin
Marybeth           Pat
6                  SET 2
Jim                Jim
Ben                Zoe
Zoe                Frederick
Joey               Annabelle
Frederick          Joey
Annabelle          Ben
5                  SET 3
John               John
Bill               Fran
Fran               Cece
Stan               Stan
Cece               Bill
0
*/

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> output;
  int setCounter = 1;

  while (true)
  {
    int nameCount;
    cin >> nameCount;
    if (nameCount == 0)
      break;
    vector<string> names;
    list<string> newNames;
    for (int i = 0; i < nameCount; i++)
    {
      string name;
      cin >> name;
      names.push_back(name);
    }

    list<string> frontwards;
    list<string> backwards;
    int frontBackCounter = 0;
    for (int i = 0; i < nameCount; i++)
    {
      if (frontBackCounter % 2 == 0)
        frontwards.push_back(names[i]);
      else
        backwards.push_front(names[i]);
      frontBackCounter++;
    }
    list<string> :: iterator it1;
    for (it1 = frontwards.begin(); it1 != frontwards.end(); it1++)
      newNames.push_back(*it1);

    list<string> :: iterator it2;
    for (it2 = backwards.begin(); it2 != backwards.end(); it2++)
      newNames.push_back(*it2);

    string set = "SET " + to_string(setCounter);
    output.push_back(set);

    list<string> :: iterator it3;
    for (it3 = newNames.begin(); it3 != newNames.end(); it3++)
      output.push_back(*it3);

    setCounter++;
  }
  
  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << endl;
  }

  return 0;
}
