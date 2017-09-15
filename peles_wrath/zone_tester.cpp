// This is the test driver for the Zone class.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "zone.h"

using namespace std;

int main()
{
  unsigned seed;
  seed = time(0);
  srand(seed);
  Zone zone("in an ugly jungle.", "Who dat?", "nobody");
  cout << zone.getDescription() << endl;
  zone.setDescription("in a beautiful jungle.");
  cout << zone.getDescription() << endl;
  cout << zone.getQuestion() << endl;
  zone.setQuestion("What's up?");
  cout << zone.getQuestion() << endl;
  zone.setResponse("nothing");
  zone.getResponse();
  return 0;
}
