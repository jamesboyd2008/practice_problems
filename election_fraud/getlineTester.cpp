#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  // cout << "running\n";
  ifstream inputFile;
  inputFile.open("ballot.txt");

  string one;
  string two;
  string three;
  string four;

  getline(inputFile, one);
  getline(inputFile, two);
  getline(inputFile, three);
  getline(inputFile, four);

  cout << four << "\n";

  return 0;
}
