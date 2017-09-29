/**
* <h1>Binary Search Implementation</h1>
* The binary_search program contains an implementation of
* the binary search algorithm. It asks the user for the quanitity of numbers
* through which they'd wish to search for a target number.
* It then asks the usker for each of the numbers through which they'd like to
* search, assuming that the user will input those numbers in ascending order.
* Then, it puts those numbers in a data set and asks the user for
* the number for which they'd wish to search.  Finally, the program outputs,
* to the console, the position of that number within the data set, assuming
* that it was there.
*
* @author James Boyd
* @version 1.0
* @since September 28, 2017
*/
#include <iostream>
using namespace std;

int binarySearch(int *nums, int numsSize, int target);
/*
binary search is similar to newton's method is similar to bracketing the target.
You have a target, i.e., a number you seek.
You are looking for that number in an ORDERED list of numbers.
I say again, the list must be ordered.
Here, we'll be using an array as our data structure.
STEP 1: You compare the element in the middle (middle-ish) of the array with your
target.
  IF they're equal, return the position of the middle.
  ELSE IF the target is larger than the middle,
    THEN make the new defacto lower bound of the array the element immediately
    above the middle.
  ELSE IF the target is lower than the middle,
    THEN make the new defacto upper bound of the array the element immediately
    below the middle.
  ELSE repeat step one until you've found the target or concluded that the
  target is not within the array.
*/


/**
* This is the main function which makes use of the binarySearch function.
* @return int This returns 0.
*/
int main()
{
  int *nums;
  int numsCount;

  cout << "Through what quantity of numbers would you like to search? ";
  cin >> numsCount;

  nums = new int [numsCount];

  // get the numbers from the user
  cout << "Input the numbers in ascending order:\n";
  int newNum;
  for (int index = 0; index < numsCount; index++)
  {
    cin >> newNum;
    nums[index] = newNum;
  }

  // get the target from the user
  int target;
  cout << "For which number you entered would you like to know the index? ";
  cin >> target;

  cout << "The position of " << target << " is "
       << binarySearch(nums, numsCount, target) << "\n";
}

// assumes array is in order and that the requested number is in the array.
int binarySearch(int *nums, int numsSize, int target)
{
  int low = 0,
      high = numsSize - 1,
      middle;

  while (low < high)
  {
    middle = (low + high) / 2;
    if (target > nums[middle])
      low = middle + 1;
    else
      high = middle;
  }

  return low;
}
