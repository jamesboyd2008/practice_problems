// The function for reading test case data from a file

using namespace std;

/**
 * a file reader that creates a circular linked list.
 * Uses <fstream>
 * Uses <vector>
 * Uses "list_node.h"
 * @param file a string, the name of the input file
 * @param players a vector of ListNodePtr's
 * @param playerCount an integer pointer
 * @param wordCount an integer, the number of words in the rhyme
 * @param rhyme a string pointer
 * @return players a vector<ListNodePtr>
 */
vector<ListNodePtr> inputFileReader
  (
    string file,
    vector<ListNodePtr> players,
    int* playerCount,
    int* wordCount,
    string* rhyme
  )
{
  int newPlayerCount;

  ifstream inputFile;
  inputFile.open(file);

  inputFile >> newPlayerCount;
  *playerCount = newPlayerCount;

  if (*playerCount < 2)
    return players;

  int firstIndex = *playerCount - 1;
  string firstName, name;
  inputFile >> firstName;
  ListNodePtr firstPlayer = new ListNode(firstName, firstIndex);
  players.push_back(firstPlayer);

  int j = 1;
  for (int i = *playerCount - 2; i >= 0; i--)
  {
    inputFile >> name;
    ListNodePtr newPlayer = new ListNode(name, i);
    players.push_back(newPlayer);
    addNode(players[j], players[j - 1]);
    j++;
  }

  // makes it a circular linked list
  addNode(players[0], players[players.size() - 1]);

  string word;
  int wordIncrementor = 0;
  while (inputFile >> word)
  {
    *rhyme += word + " ";
    wordIncrementor++;
  }

  *wordCount = wordIncrementor;

  inputFile.close();
  return players;
}
