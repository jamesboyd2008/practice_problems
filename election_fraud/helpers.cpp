// This file contains the functions for reading/writing to/from files.
// #include <fstream>
// #include <string>
// #include "ticketHelpers.cpp"
// using namespace std;

/**
* Reads in the ballot from a separate file and returns a pointer to a
* ballot structure.
* The ballot file is structured thusly:
* The first line of the file will contain the number of categories, n.
* the next n lines will contain the following:
* the number of choices for that category,
* the name of the category
* and the choices for that category.
* The end of the ballot information will be marked by a 0.
* @param ballotFile a string indicating the file that holds the ballot data.
* @return Ballot all the things upon which the voters will vote
*/
Ballot ballotReader(string ballotFile)
{
  ifstream inputFile;
  inputFile.open(ballotFile);

  // assumes there are no more than 100 things upon which to vote per ballot
  Ticket *tickets = new Ticket[100];
  Ticket tempTicket;

  int ticketQuantity;
  inputFile >> ticketQuantity;
  inputFile.ignore();
  // inputFile.ignore('\n');
  // cout << "quantity plus 5: " << ticketQuantity + 5 << endl;

  // iterate over each ticket item on the ballot
  for (int ticketCount = 0; ticketCount < ticketQuantity; ticketCount++)
  {
    int candidateQuantity;
    string ticketOffice;

    // assumes there's no more than 10 candidates per ticket
    string *candidates = new string[10];

    inputFile >> candidateQuantity;
    inputFile.ignore();
    
    getline(inputFile, ticketOffice);

    // iterate over each candidate on the individual ticket
    for (
      int candidateCount = 0;
      candidateCount < candidateQuantity;
      candidateCount++
    )
    {
      getline(inputFile, candidates[candidateCount]);
    }

    // Ticket tempTicket(ticketOffice, candidates);
    tempTicket.office = ticketOffice;
    tempTicket.candidates = candidates;
    tickets[ticketCount] = tempTicket;
    // refacotr: collect garbage

  }
  // refactor: collect garbage

  inputFile.close();

  // make a bunch of tickets
  // make a ballot out of those tickets
  Ballot ballot(ticketQuantity, tickets);
  return ballot;

  // account for 0
}

// reads in the posted list of votes from a separate file, taking the name of
// the file as a string argument.
void voteReader(string votesFile)
{

}

// iterates over votes data structure to compute the results for the election.
// writes the results of the election
// to a text file for each ballot item (the string argument),
// followed by a TAB
// the number of votes received by each choice for that ballot item,
// followed by a TAB
// and the percentage (to 2 decimal places) for each ballot item.
void tallyVotes(string resultsFile)
{

}
