/*
This program simulates an election. It asks the user for input which it
uses to produce the results of an election.
*/
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
#include "ticketIterator.cpp"
#include "voterIterator.cpp"
#include "candidateIterator.cpp"
#include "tallyVotes.cpp"
#include "outputResults.cpp"
using namespace std;

int main()
{
  cout << "\x1B[2J\x1B[H"; // clears the screen on mac
  // system("cls"); // clears the screen on windows

  // create a vector to hold all the voters from the election;
  vector<Voter*> voters;

  string ballotFileName, voteFileName;
  cout << "Let's simulate an election. [press enter]";
  cin.get();

  cout << "\x1B[2J\x1B[H"; // clears the screen on mac
  // system("cls"); // clears the screen on windows

  cout << "What is the name of the file containing the ballot information?\n";
  cout << "ballot_1.txt\n";
  cout << "ballot_2.txt\n";
  cout << "ballot_3.txt\n";
  cout << "ballot_4.txt\n";
  cout << "Please choose from one of the above: ";
  cin >> ballotFileName;

  cout << "\x1B[2J\x1B[H"; // clears the screen on mac
  // system("cls"); // clears the screen on windows

  /* create the ballot from data from a file.
  Ballot objects are composed of Ticket objects,
  Ticket objects are composed of Candidate objects.
  */
  Ballot *ballot = ballotReader(ballotFileName);

  cout << "What is the name of the file containing the corresponding votes?\n";
  cout << "votes_1.txt\n";
  cout << "votes_2.txt\n";
  cout << "votes_3.txt\n";
  cout << "votes_4.txt\n";
  cout << "Please choose the corresponding file from above: ";
  cin >> voteFileName;

  cout << "\x1B[2J\x1B[H"; // clears the screen on mac
  // system("cls"); // clears the screen on windows

  // read in vote data from a file
  voters = voteReader(voteFileName);

  // calculate the results
  /* Alogrithm:
  * Iterate over the tickets one the ballot
    * calculate results for each ticket
      * iterate over the candidates on the ticket
        * iterate over voters
          * read i_th posistion from c-string
            * use
                - ascii values,
                - the position in the c-string,
                - and no. of candidates on that ticket
              to determine
                - raw votes received, and
                - percentage of total vote received.
        * put those results into the Candidate objects
  */
  tallyVotes(ballot, voters, "results.txt");

  // write the results to a file
  outputResults(ballot);

  cout << "The results of the election ";
  cout << "have been written to a file named results.txt\n";

  return 0;
}
