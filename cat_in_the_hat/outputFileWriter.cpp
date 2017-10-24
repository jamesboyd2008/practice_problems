using namespace std;

/**
 * This function writes the winning position to a file.
 * @param playerCount an integer representing the quantity of players.
 * @param rhyme a string, the rhyme.
 * @param winningPosition an integer, where Alice must stand to win.
 * @param winner a string, the name of the winner.
 */
void outputFileWriter
  (int playerCount, string rhyme, int winningPosition, string* winner)
{
  ofstream outputFile;
  outputFile.open("results.txt");
  outputFile << "Alice should stand in position "
             << (winningPosition + 1) << "\n"
             << "where " << *winner << " was originally standing\n"
             << "to win the game \nwhile playing with "
             << playerCount << " players \nusing the rhyme: "
             << rhyme << "\n";

  outputFile.close();
}
