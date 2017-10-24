// This program simulates gameplay.

using namespace std;

/**
This function tells Alice where to stand to win the game.
@param players a vector of type ListNodePtr containing the 2-10 players.
@param wordCount an integer representing the number of words in the rhyme.
@param winner a string, the name of the winner based on their positions from input.
@return winningPosition an integer representing where to stand to win.
*/
int gameSimulation(vector<ListNodePtr> players, int wordCount, string* winner)
{
  int winningPosition = 0,
      deleteMe = 0,
      remaining = players.size();

  ListNodePtr pseudoHead = players[players.size() - 1];

  /* iterate over the circular linked list, eliminating players,
  until there is only one left. */
  for (int i = 0; i < players.size() - 1; i++)
  {
    for (int j = 0; j < wordCount; j++)
    {
      pseudoHead = pseudoHead->next;
    }

    deleteNode(pseudoHead->previous);
  }

  winningPosition = pseudoHead->position;
  *winner = pseudoHead->name;

  return winningPosition;
}
