/**
* Iterates over votes data structure to compute the results for the election.
* writes the results of the election to a text file.
* @param ballot the things upon which voters voted.
* @param voters the Voter objects who voted.
* @param resultsFile the file to which the election results will be written.
*/
void tallyVotes(Ballot *ballot, vector<Voter*> voters, string resultsFile)
{
  ofstream outputFile;
  outputFile.open(resultsFile);

  /* das algo:
  Iterate over ballot.
    calculate results for each ticket
      iterate over voters
        read i_th posistion from c-string
          use
            - ascii values,
            - the position in the c-string,
            - and no. of candidates on that ticket
          to determine
            raw votes received, and
            percentage of total vote received.
    put those results into the output file
  */
  outputFile << "\n";

  Ticket ticket;
  int ordinalsConsumed = 0; // candidates "accounted for" so far

  // iterate over the tickets on the ballot
  for (int ticket_i = 0; ticket_i < ballot->maxTickets; ticket_i++)
  {
    ticket = ballot->tickets[ticket_i]; // focal ticket

    outputFile << ticket.office << "\n"; // write office to file

    // iterate over the candidates on the ticket
    for (
      int candidate_i = 0;
      candidate_i < ticket.candidateQuantity;
      candidate_i++
    )
    {
      Candidate candidate = ticket.candidates[candidate_i];

      // calculate candidate.votesWon and candidate.percentWon here
      // iterate over voters here
      // 'A''s ordinal is 65
      int votes = 0;
      int stance;
      for (int voter = 0; voter < voters.size(); voter++)
      {
        char *positions = new char[ballot->maxTickets];
        positions = voters[voter]->getPositions();
        // outputFile << static_cast<int>(positions[ticket_i] - (65 + ordinalsConsumed)) << "\n";
        stance = static_cast<int>(positions[ticket_i] - (65 + ordinalsConsumed));

        // find the candidate for whom the voter voted and increment their votes
        if (stance == candidate_i)
        {
          candidate.votesWon++;
        }
      }

      candidate.percentWon =
        (static_cast<double>(candidate.votesWon) / voters.size()) * 100;

      outputFile << left << setw(25) // make it pretty
           << candidate.name // write candidate to file
          //  << "num votes" << "  " // write quantity of votes for them
           << candidate.votesWon << "  " // write quantity of votes for them
           // write their percentage of votes won
           << setprecision(2) << fixed << candidate.percentWon << "%\n";
    }

    // account for 'ABC...' ballot style
    ordinalsConsumed += ticket.candidateQuantity;

    outputFile << "\n";
  }

  outputFile.close();
}
