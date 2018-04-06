// prog 5 multiway trees
#include <iostream>

using namespace std;

int main()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        cout << "\nChoose an option:\n"
             << "1. Compute the distance between two sets of coordinates.\n"
             << "2. Find the nearest city to a set of coordinates.\n"
             << "3. Add a city to the data set.\n"
             << "4. Quit.\n";
        int response;
        cin >> response;
        cout << "\n";

        switch(response)
        {
            case 1:
                // 1. Compute the distance between two sets of coordinates.
                cout << "Input the first latitude: ";
                cout << "\n...\n";
                break;
            case 2:
                // 2. Find the nearest city to a set of coordinates.
                cout << "Input the latitude: ";
                cout << "Input the longitude: ";
                break;
            case 3:
                // 3. Add a city to the data set.
                // • Otherwise, prompt the user for a city name and its coordinates (lat, lon).
                // • Once you have the city’s information:
                //     o Insert the city into the tree if it is not there already.
                //     o Give the user two options:
                //         § Find  the  nearest  (other)  state  capitol  and  report  its  distance  from  the
                //         given city.
                //         § Find and list the names and distances of all cities within a user-provided
                //         distance r in miles from the given city.
                cout << "Input the name of the city: ";
                break;
            case 4:
                keepGoing = false;
                break;
            default:
                cout << "Please choose 1, 2, 3, or 4.\n\n";
        }
    }

    return 0;
}
