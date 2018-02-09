/******************************************************************************
This program outputs decrypted input.

The puzzle is from https://open.kattis.com/problems/drmmessages

Title: DRM Messages
DRM Encryption is a new kind of encryption. Given an encrypted string (which 
we’ll call a DRM message), the decryption process involves three steps: 
Divide, Rotate and Merge. This process is described in the following example 
with the DRM message “EWPGAJRB”:

Divide
– First, divide the message in half to “EWPG” and “AJRB”.
Rotate
– For each half, calculate its rotation value by summing up the values of each 
character (A=0,B=1,…,Z=25). The rotation value of “EWPG” is 
4+22+15+6=47. Rotate each character in “EWPG” 47 positions 
forward (wrapping from Z to A when necessary) to obtain the new string “ZRKB”. 
Following the same process on “AJRB” results in “BKSC”.
Merge
– The last step is to combine these new strings (“ZRKB” and “BKSC”) by rotating 
each character in the first string by the value of the corresponding character 
in the second string. For the first position, rotating ‘Z’ by ‘B’ means moving 
it forward 1 character, which wraps it around to ‘A’. Continuing this process 
for every character results in the final decrypted message, “ABCD”.
Input
The input contains a single DRM message to be decrypted. All characters in the 
string are uppercase letters and the string’s length is even and ≤15000.

Output
Display the decrypted DRM message.

Sample Input 1	                Sample Output 1
EWPGAJRB                        ABCD

Sample Input 2	                Sample Output 2
UEQBJPJCBUDGBNKCAHXCVERXUCVK    ACMECNACONTEST

*******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int main()
{
  string message, firstHalf, secondHalf;
  cin >> message;
  int half = message.size() / 2;
  firstHalf = message.substr(0, half);
  secondHalf = message.substr(half, half);
  string halves[2] = { firstHalf, secondHalf };
  
  for (int i = 0; i < 2; i++)
  {
    int tally = 0;
    for (int j = 0; j < halves[i].size(); j++)
    {
      tally += (int)halves[i][j] - 65;
    }
    for (int j = 0; j < halves[i].size(); j++)
    {
      halves[i][j] = (char)((((int)halves[i][j] - 65 + 26 + tally) % 26) + 65);
    }
  }
  
  for (int i = 0; i < half; i++)
  {
    int rotate = (int)halves[1][i] - 65;
    halves[0][i] = (char)((((int)halves[0][i] - 65 + 26 + rotate) % 26) + 65); 
  }
  
  cout << halves[0] << endl;
  
  return 0;
}

