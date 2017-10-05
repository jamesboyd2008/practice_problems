/**
* Reads in the ballot from a separate file and returns a ballot structure.
* The ballot file is structured thusly:
* The first line of the file will contain the number of categories, n.
* the next n lines will contain the following:
* the number of choices for that category,
* the name of the category
* and the choices for that category.
* The end of the ballot information will be marked by a 0.
* @param ballotFile a string indicating the file that holds the ballot data.
* @return *Ballot all the things upon which the voters will vote
*/
Ballot *ballotReader(string ballotFile)
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
    string *candidates = new string[26];

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

    tempTicket.office = ticketOffice;
    tempTicket.candidateQuantity = candidateQuantity;

    // create candidates
    tempTicket.candidates = new Candidate[candidateQuantity];
    for (int candidate_i = 0; candidate_i < candidateQuantity; candidate_i++)
    {
      tempTicket.candidates[candidate_i].name = candidates[candidate_i];
    }

    tickets[ticketCount] = tempTicket;
  }

  inputFile.close();

  Ballot *ballot = new Ballot();
  *ballot = Ballot(ticketQuantity, tickets);
  return ballot;

  // account for 0?
}
