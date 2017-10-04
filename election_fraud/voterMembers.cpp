// This file contains implementations of Voter class member functions.

// Initializes the object with a ballot with no more than 100 questions.
Voter::Voter() { positions = new char[100]; }

// An overloaded constructor that takes the number of votes and
// a string of votes (e.g. “ACFHJ”).
Voter::Voter(int newId, int voteCount, string newPositions)
{
  id = newId;
  positions = new char[voteCount + 1];

  // turn a string into a c-string and assign it to instance private member
  strcpy(positions, newPositions.c_str());
}

// Copy constructor
Voter::Voter(const Voter& voter_object) : id(voter_object.getId())
{
  positions = new char[100];
  positions = voter_object.getPositions();
}

// Destructor - returns dynamic memory to the freestore
Voter::~Voter() { delete [] positions; }

// Overloads assignment operator
Voter& Voter::operator=(const Voter &rightVoter)
{
  id = rightVoter.getId();
  positions = rightVoter.getPositions();
  return *this;
}

// returns the voter's id number
int Voter::getId() const { return id; }

// a mutator function that set's the voter's id taking an integer argument.
void Voter::setId(int newId) { id = newId; }

// returns the voter's votes as a cstring
char *Voter::getPositions() const { return positions; }

// a mutator function that sets the voter's positions, taking a
// character array of votes as an argument.
void Voter::setPositions(char newPositions[]) { positions = newPositions; }
