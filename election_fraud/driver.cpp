//  This program simulates an election
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "ticketHelpers.cpp"
#include "voter.h"
#include "voterMembers.cpp"
#include "ballotReader.cpp"
#include "voteReader.cpp"
#include "tallyVotes.cpp"
using namespace std;

int main()
{
  vector<Voter*> voters; // all the voters from the election;
  Ballot ballot = ballotReader("ballot.txt");
  // cout << ballot.maxTickets << "\n";
  // cout << ballot.tickets[0].office << "\n";
  // cout << ballot.tickets[0].candidates[0] << "\n";
  // cout << ballot.tickets[0].candidates[1] << "\n";
  // cout << ballot.tickets[1].office << "\n";
  // cout << ballot.tickets[1].candidates[0] << "\n";
  // cout << ballot.tickets[1].candidates[1] << "\n";
  // cout << ballot.tickets[1].candidates[2] << "\n";
  // cout << ballot.tickets[2].office << "\n";
  // cout << ballot.tickets[2].candidates[0] << "\n";
  // cout << ballot.tickets[2].candidates[1] << "\n";
  // cout << ballot.tickets[0].candidates[2] << "\n";

  voters = voteReader("rawVotes.txt");

  // cout << voters.at(0)->getId() << " " << voters.at(0)->getPositions() << "\n";
  // cout << voters.at(1)->getId() << " " << voters.at(1)->getPositions() << "\n";
  // cout << voters.at(2)->getId() << " " << voters.at(2)->getPositions() << "\n";
  // cout << voters.at(3)->getId() << " " << voters.at(3)->getPositions() << "\n";
  // cout << voters.at(4)->getId() << " " << voters.at(4)->getPositions() << "\n";
  // cout << "voters size: " << voters.size() << "\n";

  tallyVotes(ballot, voters, "results.txt");
  return 0;
}
