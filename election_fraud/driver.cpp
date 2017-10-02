//  This program simulates an election
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ticketHelpers.cpp"
#include "voter.h"
#include "voterMembers.cpp"
#include "helpers.cpp"
using namespace std;

int main()
{
  vector<Voter> voters; // all the voters from the election;
  Ballot ballot = ballotReader("ballot.txt");
  cout << ballot.maxTickets << "\n";
  cout << ballot.tickets[0].office << "\n";
  cout << ballot.tickets[0].candidates[0] << "\n";
  cout << ballot.tickets[0].candidates[1] << "\n";
  cout << ballot.tickets[1].office << "\n";
  cout << ballot.tickets[1].candidates[0] << "\n";
  cout << ballot.tickets[1].candidates[1] << "\n";
  cout << ballot.tickets[1].candidates[2] << "\n";
  cout << ballot.tickets[2].office << "\n";
  cout << ballot.tickets[2].candidates[0] << "\n";
  cout << ballot.tickets[2].candidates[1] << "\n";
  cout << ballot.tickets[0].candidates[2] << "\n";

  // voteReader(/* votes file name */);
  // cout << "derp nation\n";
  // tallyVotes(/* destination file name */);
  return 0;
}
