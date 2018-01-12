/*
* This function iterates over all the voters,
* tallying up their votes for a given candidate.  Then, it adds the vote
* totals to each candidate.
* @param ballot the election ballot
* @param voters the vector of voter pointers
* @param ticket_i the index of the ticket of concern
* @param ordinalsConsumed the number of letters
  that have appeared on the ballot so far.
* @param candidate a pointer to the candidate whose vote's are being tallied
* @param candidate_i the index of candidate
*/
void voterIterator(
  Ballot *ballot,
  vector<Voter*> voters,
  int ticket_i,
  int ordinalsConsumed,
  Candidate *candidate,
  int candidate_i
)
{
  int votes = 0;
  int stance;
  for (int voter = 0; voter < voters.size(); voter++)
  {
    char *positions = new char[ballot->maxTickets];
    positions = voters[voter]->getPositions();
    stance =
      static_cast<int>(positions[ticket_i] - (65 + ordinalsConsumed));

    // find the candidate for whom the voter voted and increment their votes
    if (stance == candidate_i) { candidate->votesWon++; }
  }
  candidate->percentWon =
    (static_cast<double>(candidate->votesWon) / voters.size()) * 100;
}
