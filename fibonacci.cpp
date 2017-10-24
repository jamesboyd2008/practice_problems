// Fibonacci number calculators
#include <iostream>

using namespace std;

int recursiveFibo(int n); // returns the nth Fibonacci number

int iterativeFibo(int n); // returns the nth Fibonacci number

int main()
{
  int n;

  cout << "How many fibonaccis? ";
  cin >> n;
  cout << "Here's the " << n << "th fibonacci number caluclated\n";
  cout << "recursively: " << recursiveFibo(n) << "\n";
  cout << "iteratively: " << iterativeFibo(n) << "\n";

  return 0;
}

int recursiveFibo(int n)
{
  // base cases
  if (n == 1)
    return 1;
  if (n == 0)
    return 0;

  return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}

int iterativeFibo(int n)
{
  int num1 = 0,
      num2 = 1,
      temp;

  for (int i = 1; i < n; i++)
  {
    temp = num2 + num1;
    num1 = num2;
    num2 = temp;
  }

  return temp;
}
