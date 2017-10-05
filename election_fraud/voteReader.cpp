/**
Reads in the posted list of votes from a separate file, taking the name of
the file as a string argument and returning a vector pointer of Voter
objects.
*/

vector<Voter*> voteReader(string votesFile)
{
  vector<Voter*> voters; // this is what gets returned

  ifstream inputFile;
  inputFile.open(votesFile);

  string value, id, posistionsStr;

  int index = 0;

  // Reads in voter data until EOF is reached
  while (inputFile >> value)
  {
    id = value;
    inputFile >> posistionsStr;

    stringstream idStream(id);
    int newId;
    idStream >> newId;

    // create a voter pointer with that data
    Voter *voter = new Voter(newId, posistionsStr.size(), posistionsStr);
    voters.push_back(voter);
  }

  inputFile.close();

  return voters;
}
