// this program generates random numbers
#include <iostream>

using namespace std;

int main()
{
  // using the linear congruential pseudorandom number generation method
  int seed = 3,
      modulus = 7,
      multiplier = 4,
      increment = 1;

  for (int i = 0; i < 10; i++)
  {
    seed = (multiplier * seed + increment) % modulus;
    cout << seed << "\n";
  }

  return 0;
}
