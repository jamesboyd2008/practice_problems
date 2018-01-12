/*
* This function iterates over all the candidates,
* using their location on the ticket
* to know what to search through the voter for.
* @param ballot the election ballot
* @param voters the vector of voter pointers
* @param ticket_i the index of the ticket of concern
* @param ordinalsConsumed the number of letters
  that have appeared on the ballot so far.
* @param ticket a pointer to the ticket under consideration
*/
void candidateIterator
(
  Ballot *ballot,
  vector<Voter*> voters,
  int ticket_i,
  int ordinalsConsumed,
  Ticket *ticket
)
{
  // iterate over the candidates on the ticket
  for
  (
    int candidate_i = 0;
    candidate_i < ticket->candidateQuantity;
    candidate_i++
  )
  {
    Candidate *candidate = new Candidate();
    candidate = &ticket->candidates[candidate_i];

    // iterate over voters
    voterIterator
    (
      ballot,
      voters,
      ticket_i,
      ordinalsConsumed,
      candidate,
      candidate_i
    );
  }
}
