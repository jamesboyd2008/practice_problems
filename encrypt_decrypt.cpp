// this program encrypts and decrypts strings
#include <iostream>
#include <string>
using namespace std;

int main()
{
  // get the input

  // find the solution

  /* encrypt_it
  Suppose we want to encrypt the string “my pie”.

  First, convert each symbol sisi into v(si)v(si): [13,25,0,16,9,5][13,25,0,16,9,5].
  Next, compute each uiui: [13,38,38,54,63,68][13,38,38,54,63,68].
  Then, use modulus on the uiui: [13,11,11,0,9,14][13,11,11,0,9,14].
  Finally, convert these back to symbols: “mkk in”.
  */

  /* decrypt_it
  - read in the symbols
  - convert each one into a number
    - if the letter is a space, give it a zero
    - a through z is 97 through 122 ... so subtract 97


  */
  // cout << (static_cast<int>('m') - 96) % 27 << endl; // 13
  // cout << (static_cast<int>('k') - 96) % 27 << endl; // 11
  // cout << (static_cast<int>('k') - 96) % 27 << endl; // 11
  // cout << '0' << endl; // b/c it's a space
  // cout << (static_cast<int>('i') - 96) % 27 << endl; // 9
  // cout << (static_cast<int>('n') - 96) % 27 << endl; // 14

  char operation;
  cin >> operation;
  cin.get(); // eats a single whitespace

  if (operation == 'd')
  {
    string input;
    getline(cin, input);
    // cout << input.size() << endl;
    const int inputLength = input.size();
    // convert it into a c-string
    char encrypted[200];
    strcpy(encrypted, input.c_str());
    // cout << encrypted[0] << endl;

    int halfway[inputLength]; // u sub i
    for (int i = 0; i < inputLength; i++)
    {
      if (encrypted[i] == ' ')
      {
        halfway[i] = 0;
      }
      else
      {
        halfway[i] = (static_cast<int>(encrypted[i]) - 96) % 27;
      }
    }

    for (int i = 0; i < inputLength; i++)
    {
      cout << halfway[i] << ' ';
    }

    int almostThere[inputLength];
    almostThere[0] = halfway[0];
    int sum = almostThere[0];

    for (int i = 1; i < inputLength; i++)
    {
      sum += halfway[i];
      almostThere[i] = sum;
    }

    // for (int i = 0; i < inputLength; i++)
    // {
    //   cout << almostThere[i] << ' ';
    // }

  }

  // output the result

  return 0;
}
