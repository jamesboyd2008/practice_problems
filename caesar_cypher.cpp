// classic caesar cypher decrytion algo
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string message;
  cout << "Please input the encrypted message: ";
  getline(cin, message);
  const char *c_message = message.c_str();

  for (int i = 0; i < strlen(c_message); i++)
  {
    if (message[i] == ' ')
      cout << ' ';
    else
      cout << static_cast<char>
           (((static_cast<int>(message[i]) - 65 + 26 - 3) % 26) + 65);
  }

  cout << "\n";

  return 0;
}
