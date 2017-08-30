#include <iostream>

using namespace std;

int main() {

  // input number of cases
  int numCases;
  cout << "Input the number of test cases: ";
  cin >> numCases;


  for (int i = 0; i < numCases; i++) {
    int successes = 0;
    int numShips, distanceTravelling;
    // input the number of ships and the distance to be travelled
    cout << "Input number of ships: ";
    cin >> numShips;
    cout << "Input the distance to be travelled: ";
    cin >> distanceTravelling;

    for (int s = 0; s < numShips; s++) {
      int speed, fuelCapacity, burnRate;
      // input individual ship data
      cout << "Input the speed of the ship: ";
      cin >> speed;
      cout << "Input the fuel capacity of the ship: ";
      cin >> fuelCapacity;
      cout << "Input the rate at which she ship burns fuel: ";
      cin >> burnRate;

      // be careful with ints!!
      // (float)(distanceTravelling) / (float)(speed) // => gives us hours
      // test the variable declaration and typecasting ideas
      float timeAvailable = (float)(distanceTravelling) / speed;
      float distanceCapable = (float)(fuelCapacity) / burnRate;

      if (distanceCapable >= timeAvailable) {
        successes++;
      }
    }

    cout << "The number of ships that are capable of making the trip: ";
    cout << successes << endl;
  }
}
