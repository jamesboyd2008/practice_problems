// This file contains implementations of Voter class member functions.
#include <iostream>
using namespace std;

// Initializes the object with a ballot with no more than 100 questions.
Voter::Voter()
{

}


// An overloaded constructor that takes the number of votes and
// a string of votes (e.g. “ACFHJ”).
Voter::Voter(int voteCount, string newPositions)
{

}


// Copy constructor
Voter::Voter(const Voter& voter_object)
{

}


// Destructor - returns dynamic memory to the freestore
Voter::~Voter()
{

}


// Overloads assignment operator
// Voter::Voter& operator=(const Voter &rightVoter)
// {
//
// }


// returns the voter's id number
int Voter::getId()
{

}


// a mutator function that set's the voter's id taking an integer argument.
void Voter::setId(int newId)
{

}


// returns the voter's votes as a cstring
char Voter::getPositions()
{

}


// a mutator function that sets the voter's positions, taking a
// character array of votes as an argument.
void Voter::setPositions(const char newPositions[])
{

}
