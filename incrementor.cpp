#include <iostream>

using namespace std;

void incrementor(int* input)
{
  *input += 1;
}

int main()
{
  int *input = new int;

  cout << "input something: ";
  cin >> *input;

  incrementor(input);

  cout << "something plus one: " << *input << endl;

  input = new int;
  delete input;

  return 0;
}
