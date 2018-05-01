#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Planet
{
public:
    Planet();
    Planet(string newName, int newX, int newY, int newZ);
    string getName();
    int getX();
    int getY();
    int getZ();
    int distanceTo(Planet destination);
private:
    string name;
    int x, y, z;
};

Planet::Planet()
{
    name = "Planet";
    x = y = z = 0;
}
Planet::Planet(string newName, int newX, int newY, int newZ)
{
    name = newName;
    x = newX;
    y = newY;
    z = newZ;
}
string Planet::getName()
{
    return name;
}
int Planet::getX()
{
    return x;
}
int Planet::getY()
{
    return y;
}
int Planet::getZ()
{
    return z;
}
int Planet::distanceTo(Planet destination)
{
    // d(P_1, P_2) = sqrt( (x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2 )
    double distance = sqrt(
        pow( ( destination.getX() - x ), 2 ) +
        pow( ( destination.getY() - y ), 2 ) +
        pow( ( destination.getZ() - z ), 2 )
    );
    return round(distance);
}


int main()
{
    // dynamic arrays
    int *dArray;
    // int sizey;

    // construct adjacency matrix from input using distance formula a bunch
    // then run dijkstra's algo

    int sizey = 10;
    // cout << "Input size: ";
    // cin >> sizey;
    // dArray = new int[12];
    dArray = new int[sizey];



    delete [] dArray;
    dArray = NULL;

    string results = "", name, enterPortal, exitPortal, start, end;
    int cases, planetCount, portalCount, x, y, z, queryCount;
    double distance = 11.7;
    int roundedDistance = round(distance);
    cout << "\n\n\nEnter the name of the input file: \n\n\n";
    // cin >> inputFileName;
    ifstream infile;
    // infile.open(inputFileName);
    infile.open("sample_input.txt");

    infile >> cases; // quantity of test cases
    for (int i = 1; i <= cases; i++) // iterate over test cases
    {
        // vector<Planet> planets;
        Planet planets[planetCount];
        results += "Case " + to_string(i) + ":\n";
        infile >> planetCount; // receive quantity of planets within test case i
        for (int j = 0; j < planetCount; j++) // for each planet...
        {
            infile >> name >> x >> y >> z; // get name and coords
            Planet planet(name, x, y, z); // create a planet
            // planets.push_back(planet); // add it to the collection of planets
            planets[j] = planet; // add it to the collection of planets
        }

        // create 2D array to hold the distances between planets
        double distances[planetCount][planetCount];
        // populate the distances array with Euclidian distances
        for (int j = 0; j < planetCount; j++)
        {
            for (int k = 0; k < planetCount; k++)
            {
                distances[j][k] = planets[j].distanceTo(planets[k]);
            }
        }

        // print distances[][] for troubleshooting
        cout << "[\n";
        for (int j = 0; j < planetCount; j++)
        {
            cout << "\t";
            for (int k = 0; k < planetCount; k++)
            {
                cout << distances[j][k] << ", ";
            }
            cout << "\n";
        }
        cout << "]\n\n";



        infile >> portalCount; // receive quantity of worm holes
        for (int j = 0; j < portalCount; j++)
        {
            // make the distance between these two planets a big ol' 0
            infile >> enterPortal >> exitPortal;
            // get the indeces of distances[j][k] corresponding to the portal
                // get index out of planets[];

        }
        infile >> queryCount;
        for (int j = 0; j < queryCount; j++)
        {
            infile >> start >> end;
            results += "The distance from " + start + " to " + end + " is "
                    +  to_string(roundedDistance) + " parsecs.\n";
        }
    }
    infile.close();

    cout << results;

    // make a [planetCount x planetCount] array of distances
    // planets[thisOne][thatOne] = distance(thisOne, thatOne)
    // account for worm holes
    // now you can nearly plug n play a distance algo

    // planets[index][index] to planets[index][index]

    // if there are no black holes, it's a straight shot
    // else (there are black holes)
        // if the distance to one or more black holes,
        // followed by the destination is shorter,
            // go that way
        // else
            // it's a straight shot



    return 0;
}
