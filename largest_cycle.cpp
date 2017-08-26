#include <iostream>

using namespace std;

int max(int oldMax, int potentialMax);
int specialOperation(int seed);

/**
 * Returns an integer.
 * This function asks the user for two integers, then it returns the largest
 * cycle length of all the integers between the two input integers to perform a
 * special operation.
 */
int main()
{
  int rangeBottom, rangeTop, max;

  cout << "Please input the bottom of the range: ";
  cin >> rangeBottom;
  cout << "Please input the top of the range: ";
  cin >> rangeTop;

  // iterate over the range, looking for the new max
  // for (int i = rangeBottom; i <= rangeTop; i++)
  // {
  //   // do the special operation.  Store the result.
  //
  //   // run the result through max, storing that result.
  // }

  cout << "The longest cycle length was " << max << "\n";
  return max;
}

/**
 * Returns an integer.
 * This function takes two params, both integers,
 * @oldMax
 * @potentialMax
 * It returns the largest of the two.
 */
int max(int oldMax, int potentialMax);
{

}

/**
 * Returns an integer.
 * This function takes one param, an integer,
 * @seed
 * It returns the cycle length of the special operation.
 */
int specialOperation(int seed)
{
  // IF x % 2 != 0
  //   IF x == 1
  //     THEN return the cycle length and exit the loop.
  // ELSE x = x * 3 + 1 and exit the loop.
  // IF x % 2 == 0
  //   THEN x /= 2 and go on to the next int.
  //

}
