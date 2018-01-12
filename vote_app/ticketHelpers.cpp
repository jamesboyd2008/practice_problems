// This file defines the Candidate, Ticket, and Ballot structures.
// #include <iostream>
// #include <string>
using namespace std;

// Candidate structure definition
struct Candidate
{
  string name;
  int votesWon;
  float percentWon;
  Candidate() { votesWon = 0; }
};

// Ticket structure definition
struct Ticket
{
  string office;
  int candidateQuantity;
  Candidate *candidates;

  // Default constructor function
  Ticket() { }

  // Constructor function
  Ticket(string newOffice, int newQuantity, Candidate *newCandidates)
  {
    office = newOffice;
    candidateQuantity = newQuantity;
    candidates = newCandidates;
  }
};

// Ballot structure definition
struct Ballot
{
  int maxTickets;
  Ticket *tickets;

  // Default constructor function
  Ballot() { }

  // Constructor function
  Ballot(int newMax, Ticket *newTickets)
  {
    maxTickets = newMax;
    tickets = newTickets;
  }
};
