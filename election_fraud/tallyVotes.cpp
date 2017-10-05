/**
* Iterates over votes data structure to compute the results for the election.
* writes the results of the election to a text file. This function needs
* the voterIterator function.
* @param ballot the things upon which voters voted.
* @param voters the Voter objects who voted.
* @param resultsFile the file to which the election results will be written.
*/
void tallyVotes(Ballot *ballot, vector<Voter*> voters, string resultsFile)
{
  // Ticket ticket;
  Ticket *ticket = new Ticket();
  int ordinalsConsumed = 0; // candidates "accounted for" so far

  // iterate over the tickets on the ballot
  for (int ticket_i = 0; ticket_i < ballot->maxTickets; ticket_i++)
  {
    ticket = &ballot->tickets[ticket_i]; // focal ticket

    candidateIterator(
      ballot,
      voters,
      ticket_i,
      ordinalsConsumed,
      ticket
    );

    // account for 'ABC...' ballot style
    ordinalsConsumed += ticket->candidateQuantity;
  }
}
