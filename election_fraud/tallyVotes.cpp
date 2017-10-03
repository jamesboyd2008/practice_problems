/**
* Iterates over votes data structure to compute the results for the election.
* writes the results of the election
* to a text file for each ballot item (the string argument),
* followed by a TAB
* the number of votes received by each choice for that ballot item,
* followed by a TAB
* and the percentage (to 2 decimal places) for each ballot item.
* @param ballot the things upon which voters voted.
* @param voters the Voter objects who voted.
* @param resultsFile the file to which the election results will be written.
*/
void tallyVotes(Ballot ballot, vector<Voter*> voters, string resultsFile)
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

  // outputFile << ballot.tickets[0].office << "\n";
  // outputFile << ballot.tickets[0].candidates[0] << "\n";
  // outputFile << ballot.tickets[0].candidates[1] << "\n";
  // outputFile << ballot.tickets[1].office << "\n";
  // outputFile << ballot.tickets[1].candidates[0] << "\n";
  // outputFile << ballot.tickets[1].candidates[1] << "\n";
  // outputFile << ballot.tickets[1].candidates[2] << "\n";
  // outputFile << ballot.tickets[2].office << "\n";
  // outputFile << ballot.tickets[2].candidates[0] << "\n";
  // outputFile << ballot.tickets[2].candidates[1] << "\n";
  // outputFile << ballot.tickets[0].candidates[2] << "\n";
  //
  // outputFile << voters.at(0)->getId() << " " << voters.at(0)->getPositions() << "\n";
  // outputFile << voters.at(1)->getId() << " " << voters.at(1)->getPositions() << "\n";
  // outputFile << voters.at(2)->getId() << " " << voters.at(2)->getPositions() << "\n";
  // outputFile << voters.at(3)->getId() << " " << voters.at(3)->getPositions() << "\n";
  // outputFile << voters.at(4)->getId() << " " << voters.at(4)->getPositions() << "\n";

  outputFile.close();
}
