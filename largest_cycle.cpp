#include <iostream>

using namespace std;

int findMax(int oldMax, int potentialMax);
int cycleLength(int seed);

/**
 * Returns an integer.
 * This function asks the user for two integers, then it returns the largest
 * cycle length of all the integers between the two input integers to perform a
 * particular operation.
 */
int main() {
  int rangeBottom, rangeTop, max = 0;

  cout << "Please input the bottom of the range: ";
  cin >> rangeBottom;
  cout << "Please input the top of the range: ";
  cin >> rangeTop;

  // iterate over the range, looking for the new max
  for (int i = rangeBottom; i <= rangeTop; i++)
  {
    int testLength = cycleLength(i);

    if (testLength > max) {
      max = testLength;
    }
  }

  cout << "The longest cycle is this long: " << max << endl;
  return max;
}

/**
 * Returns an integer.
 * This function takes two params, both integers,
 * @oldMax
 * @potentialMax
 * It returns the largest of the two.
 */
int findMax(int oldMax, int potentialMax) {
  return (potentialMax > oldMax) ? potentialMax : oldMax;
}

/**
 * Returns an integer.
 * This function takes one param, an integer,
 * @seed
 * It returns the cycle length of the particular operation.
 */
 // Todo: what if it's not a positive int?
int cycleLength(int seed) {
  // Off by one error? Is 1 a corner case?
  //  1 : 1
  //  2 : 2 1
  //  8 : 3 10 5 16 8 4 2 1
  //  3 : 4 2 1
  //  6 : 5 16 8 4 2 1
  //  9 : 6 3 10 5 16 8 4 2 1
  // 17 : 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
  //  4 : 8 4 2 1
  // 20 : 9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
  //  7 : 10 5 16 8 4 2 1

  if (seed == 1) {
    return seed;
  } else if (seed % 2 == 0) {
    return 1 + cycleLength(seed / 2);
  } else {
    return 1 + cycleLength(seed * 3 + 1);
  }
}
