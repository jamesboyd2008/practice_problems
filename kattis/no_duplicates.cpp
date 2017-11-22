/*
This programs tells whether some words repeat themselves.
https://open.kattis.com/problems/nodup
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string word, all_words;
  bool flag = false;
  vector<string> words;

  getline(cin, all_words);
  stringstream streamy(all_words);
  while (streamy >> word)
  {
    words.push_back(word);
  }

  for (int i = 0; i < words.size(); i++)
  {
    word = words[i];
    for (int j = 0; j < words.size(); j++)
    {
      if (words[j] == word && j != i)
      {
        flag = true;
        cout << "no\n";
        break;
      }
    }
    if (flag)
      break;
  }

  if (!flag)
    cout << "yes\n";

  return 0;
}
