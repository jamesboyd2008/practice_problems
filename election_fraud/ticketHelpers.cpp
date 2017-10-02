// This file defines the ballot and ticket structures.
#include <iostream>
#include <string>
using namespace std;

// Ticket structure definition
struct Ticket
{
  string office;
  string *candidates;

  // Default constructor function
  Ticket() { }

  // Constructor function
  Ticket(string newOffice, string *newCandidates)
  {
    office = newOffice;
    candidates = newCandidates;
  }
};

// Ballot structure definition
struct Ballot
{
  int maxTickets;
  Ticket *tickets;

  // Constructor function
  Ballot(int newMax, Ticket *newTickets)
  {
    maxTickets = newMax;
    tickets = newTickets;
  }
};

// int main()
// {
//   // Ticket ticket;
//   // ticket.office = "super mayor";
//   // cout << ticket.office << endl;
//   // ticket.candidates[0] = "Bob";
//   // ticket.candidates[1] = "Dole";
//   // cout << ticket.candidates[0] << endl;
//   // cout << ticket.candidates[1] << endl;
//
//   // string *candidates = new string[10];
//   string *candidates = new string[3];
//   string *otherCandidates = new string[3];
//   // candidates = {"one", "two", "three"};
//   candidates[0] = "zero";
//   candidates[1] = "one";
//   candidates[2] = "two";
//
//   otherCandidates[0] = "zeroth";
//   otherCandidates[1] = "oneth";
//   otherCandidates[2] = "twoth";
//
//   Ticket ticket("derp mayor", candidates);
//   // Ticket otherTicket("derp prez", otherCandidates);
//   Ticket otherTicket;
//   Ticket thirdTicket("derp prez", otherCandidates);
//
//   otherTicket = thirdTicket;
//
//   Ticket *deezTickets = new Ticket[100];
//
//   deezTickets[0] = ticket;
//   deezTickets[1] = otherTicket;
//
//   Ballot ballot(100, deezTickets);
//
//   cout << ballot.tickets[1].candidates[2] << endl;
//   // cout << ticket.office << endl;
//   // cout << ticket.candidates[1] << endl;
//
//
// }
