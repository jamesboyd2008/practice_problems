// This is the test driver for the Zone_Map class.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "zone.h"
#include "zone_map.h"

using namespace std;

int main()
{
  unsigned seed;
  seed = time(0);
  srand(seed);

  ZoneMap theMap;

  int count = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << count << ". "
           << theMap.getZone(i, j).getDescription() << "\n"
           << theMap.getZone(i, j).getQuestion() << "\n"
           << theMap.getZone(i, j).getRightAnswer() << "\n"
           << theMap.getZone(i, j).getTtl() << "\n";
      count += 1;
    }
  }

  return 0;
}
