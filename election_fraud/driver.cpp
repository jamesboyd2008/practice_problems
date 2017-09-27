//  This program simulates an election
#include <iostream>
// include file stream?
// #include "voter.h"
// #include "voterMembers.cpp"
using namespace std;

void ballotReader(string ballotFile);
// reads in the ballot from a separate file, taking the name of the file as a
// string argument.
// The ballot file is structured thusly:
// The first line of the file will contain the number of categories, n.
// the next n lines will contain the following:
  // the number of choices for that category,
  // the name of the category
  // and the choices for that category.
// The end of the ballot information will be marked by a 0.

void voteReader(string votesFile);
// reads in the posted list of votes from a separate file, taking the name of the
// file as a string argument.

void tallyVotes(string resultsFile);
// iterates over votes data structure to compute the results for the election. 
// writes the results of the election
// to a text file for each ballot item (the string argument),
// followed by a TAB
// the number of votes received by each choice for that ballot item,
// followed by a TAB
// and the percentage (to 2 decimal places) for each ballot item.

int main()
{
  vector<string> votes; // all the votes from the election;
  ballotReader(/* ballot file name */);
  voteReader(/* votes file name */);
  tallyVotes(/* destination file name */);
  return 0;
}
