/*
This function writes the results of the election to a file.
@param ballot a pointer to a Ballot object containing
the election data to be written to a file.
*/
void outputResults(Ballot *ballot)
{
  ofstream outputFile;
  outputFile.open("results.txt");

  outputFile << "\n";

  // Ticket ticket;
  Ticket *ticket = new Ticket();
  int ordinalsConsumed = 0; // candidates "accounted for" so far

  // iterate over the tickets on the ballot
  for (int ticket_i = 0; ticket_i < ballot->maxTickets; ticket_i++)
  {
    ticket = &ballot->tickets[ticket_i]; // focal ticket

    outputFile << ticket->office << "\n"; // write office to file

    // iterate over the candidates on the ticket
    Candidate *candidate = new Candidate();
    for (
      int candidate_i = 0;
      candidate_i < ticket->candidateQuantity;
      candidate_i++
    )
    {
      candidate = &ticket->candidates[candidate_i];

      outputFile << left << setw(25) // make it pretty
           << candidate->name // write candidate to file
          //  << "num votes" << "  " // write quantity of votes for them
           << candidate->votesWon << "  " // write quantity of votes for them
           // write their percentage of votes won
           << setprecision(2) << fixed << candidate->percentWon << "%\n";

      // account for 'ABC...' ballot.ticket.candidate style
      ordinalsConsumed += ticket->candidateQuantity;
    }
    outputFile << "\n";
  }
  outputFile.close();
}
