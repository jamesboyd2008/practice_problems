#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
  int i = 4;
  double d = 4.0;
  string s = "HackerRank ";

  // Declare second integer, double, and String variables.
  int second_i;
  double second_d;
  string second_s;

  // Read and save an integer, double, and String to your variables.
  // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
  cin >> second_i;
  cin >> second_d;
  getline(cin >> ws, second_s);

  // Print the sum of both integer variables on a new line.
  cout << i + second_i << endl;

  // Print the sum of the double variables on a new line.
  cout << fixed << setprecision(1) << d + second_d << endl;

  // Concatenate and print the String variables on a new line
  // The 's' variable above should be printed first.
  string combo = s + second_s;
  cout << combo;
}
