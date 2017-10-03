// Voter class declaration
// #include <iostream>
// #include "voterMembers.cpp"
// using namespace std;

class Voter
{
public:
  Voter();
  // Initializes the object with a ballot with no more than 100 questions.

  Voter(int newId, int voteCount, string newPositions);
  // An overloaded constructor that takes the number of votes,
  // an ID to be assigned to the voter,
  // and a string of votes (e.g. “ACFHJ”).

  Voter(const Voter& voter_object);
  // Copy constructor

  ~Voter();
  // Destructor - returns dynamic memory to the freestore

  Voter& operator=(const Voter &rightVoter);
  // Overloads assignment operator

  int getId();
  // returns the voter's id number

  void setId(int newId);
  // a mutator function that set's the voter's id taking an integer argument.

  char *getPositions();
  // returns the voter's votes as a cstring

  void setPositions(const char newPositions[]);
  // a mutator function that sets the voter's positions, taking a
  // character array of votes as an argument.

private:
  int id; // voter's identification number
  char *positions; // pointer to dynamic array of this voter's votes
};
