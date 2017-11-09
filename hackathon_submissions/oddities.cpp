/*
This program tells whether some integers are even or odd.
https://open.kattis.com/problems/oddities
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int test_cases, num;
  cin >> test_cases;

  vector<int> nums;

  for (int i = 0; i < test_cases; i++)
  {
    cin >> num;
    nums.push_back(num);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    num = nums[i];
    if (num % 2 == 0)
      cout << num << " is even\n";
    else
      cout << num << " is odd\n";
  }

  return 0;
}
