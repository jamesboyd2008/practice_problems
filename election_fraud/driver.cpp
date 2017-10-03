//  This program simulates an election
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "ticketHelpers.cpp"
#include "ballotReader.cpp"
#include "voter.h"
#include "voteReader.cpp"
#include "voterMembers.cpp"
#include "tallyVotes.cpp"
using namespace std;

int main()
{
  // create a vetor to hold all the voters from the election;
  vector<Voter*> voters;

  // create the ballot
  Ballot *ballot = ballotReader("ballot.txt");

  // read in vote data
  voters = voteReader("rawVotes.txt");

  // calculate the results and write them to a file
  tallyVotes(ballot, voters, "results.txt");

  return 0;
}
