/*
This program, given a string, outputs the ratios, to the whole, of
whitespace characters, lowercase letters, uppercase letters, and symbols.

This problem is from https://open.kattis.com/problems/alphabetspam

Title: Alphabet Spam
About 90 percent of the 300 billion emails sent every day are spam. Thus, a fast spam detection mechanism is crucial for large email providers. Lots of spammers try to circumvent spam detection by rewriting words like “M0n3y”, “Ca$h”, or “Lo||ery”.
A very simple and fast spam detection mechanism is based on the ratios between whitespace characters, lowercase letters, uppercase letters, and symbols. Symbols are defined as characters that do not fall in one of the first three groups.

Input
The input consists of:
one line with a string consisting of at least 1 and at most 100000 characters.

A preprocessing step has already transformed all whitespace characters to underscores (_), and the line will consist solely of characters with ASCII codes between 33 and 126 (inclusive).

Output
Output four lines, containing the ratios of whitespace characters, lowercase letters, uppercase letters, and symbols (in that order). Your answer should have an absolute or relative error of at most 10^−6.

Sample Input 1
Welcome_NWERC_participants!

Sample Output 1
0.0740740740740741
0.666666666666667
0.222222222222222
0.0370370370370370

Sample Input 2
\/\/in_US$100000_in_our_Ca$h_Lo||ery!!!

Sample Output 2
0.128205128205128
0.333333333333333
0.102564102564103
0.435897435897436
*/

#include "iomanip"
#include "iostream"
#include "string"

using namespace std;

int main()
{
  int whites, lowers, uppers, symbols;
  whites = lowers = uppers = symbols = 0;
  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++)
  {
    char focal_char = input[i];
    int ascii_code = (int)focal_char;

    if (focal_char == '_')
    {
      whites++;
    }
    else if (97 <= ascii_code && ascii_code <= 122)
    {
      lowers++;
    }
    else if (65 <= ascii_code && ascii_code <= 90)
    {
      uppers++;
    }
    else // its a symbol
      symbols++;
  }

  double total = (double)input.size();
  double white_ratio = (double)whites / total;
  double lower_ratio = (double)lowers / total;
  double upper_ratio = (double)uppers / total;
  double symbol_ratio = (double)symbols / total;

  cout << fixed << setprecision(15)
       << white_ratio << endl
       << lower_ratio << endl
       << upper_ratio << endl
       << symbol_ratio << endl;

  return 0;
}
