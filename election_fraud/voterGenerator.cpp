// This program generates the contents for the test voter data.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
  srand((int)time(0));
	// int i = 0;
	// while(i++ < 10) {
	// 	int r = rand() % 5;
	// 	cout << r << "\n";
	// }
  // cout << "\n";
  string destinationFile;
  int voterQuantity, officeQuantity, candidateQuantity;

  cout << "This program generates the contents for the test voter data, \n"
       << "assuming there are an equal number of candidates in each office.\n"
       << "Please input the name of the destination file for you voter data:\n";
  cin >> destinationFile;

  cout << "How many voters? ";
  cin >> voterQuantity;

  cout << "How many offices? ";
  cin >> officeQuantity;

  cout << "How many candidates? ";
  cin >> candidateQuantity;

  ofstream ofsteamObj;
  ofsteamObj.open(destinationFile);


  char *positions = new char[officeQuantity];
  // quotient of candidates per office;
  int candiQ = candidateQuantity / officeQuantity;
  int ordinalsConsumed;

  // loop through voters
  for (int voter = 0; voter < voterQuantity; voter++)
  {
    ordinalsConsumed = 0;
    // loop through offices
    for (int office = 0; office < officeQuantity; office++)
    {
      // set a single position
      positions[office] =
        static_cast<char>(65 + (ordinalsConsumed * candiQ) + (rand() % candiQ));
      ordinalsConsumed++;
    }
    // ofsteamObj << voter << " " << "voter data\n";
    ofsteamObj << voter << " " << positions << "\n";
  }

  return 0;
}
