#include <cmath> // pow, round
#include <fstream> // ofstream, ifstream
#include <iostream> // cin
#include <string>

using namespace std;

// This class exists for ease of association of planet names and x,y,z coords.
class Planet
{
public:
    Planet();
    Planet(string newName, int newX, int newY, int newZ);
    string getName();
    int getX();
    int getY();
    int getZ();
    int distanceFrom(Planet destination);
private:
    string name;
    int x, y, z;
};
// default constructor
Planet::Planet()
{
    name = "Planet";
    x = y = z = 0;
}
// make a planet
Planet::Planet(string newName, int newX, int newY, int newZ)
{
    name = newName;
    x = newX;
    y = newY;
    z = newZ;
}
// private member accessor function
string Planet::getName()
{
    return name;
}
// private member accessor function
int Planet::getX()
{
    return x;
}
// private member accessor function
int Planet::getY()
{
    return y;
}
// private member accessor function
int Planet::getZ()
{
    return z;
}
// This function calculates the Euclidian distance between two planets.
// input: a Planet
// output: an int, rounded from a double, the distance between the two planets.
int Planet::distanceFrom(Planet destination)
{
    // d(P_1, P_2) = sqrt( (x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2 )
    double distance = sqrt(
        pow( ( destination.getX() - x ), 2 ) +
        pow( ( destination.getY() - y ), 2 ) +
        pow( ( destination.getZ() - z ), 2 )
    );
    return round(distance);
}

// driver function
int main()
{
    string in, // the relative path to the input file
           out, // the relative path to the output file
           results = "", // string to hold all the answers
           name, // used to construct every planet.
           enterPortal, // used to identify every planet with an entry portal
           exitPortal, // used to identify every planet with an exit portal
           start, // used in all queries
           end; // used in all queries
    int cases, // the number of test cases
        planetCount, // used for every test case
        portalCount, // used for every test case
        x, // used to construct every planet
        y, // used to construct every planet
        z, // used to construct every planet
        queryCount; // used once per test case
    cout << "\nEnter the name of the input file: ";
    cin >> in; // receive input file
    cout << "\nEnter the name of the output file: ";
    cin >> out; // receive output file
    cout << endl;
    ifstream infile;
    infile.open(in); // opening input file

    infile >> cases; // quantity of test cases
    for (int i = 1; i <= cases; i++) // iterate over test cases
    {
        results += "Case " + to_string(i) + ":\n";
        infile >> planetCount; // receive quantity of planets within test case i
        Planet planets[planetCount];
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
                distances[j][k] = planets[j].distanceFrom(planets[k]);
            }
        }

        infile >> portalCount; // receive quantity of worm holes
        for (int j = 0; j < portalCount; j++) // receive all the portals
        {
            infile >> enterPortal >> exitPortal; // get entry and exit planets
            int entryIndex, exitIndex;
            for (int k = 0; k < planetCount; k++) // iterate over planets
            {
                if (planets[k].getName() == enterPortal) // is this the entry?
                    entryIndex = k;
                else if (planets[k].getName() == exitPortal) // is this exit?
                    exitIndex = k;
            }
            distances[entryIndex][exitIndex] = 0; // account for the portal
        }

        infile >> queryCount;
        for (int j = 0; j < queryCount; j++) // do this for every single query
        {
            infile >> start >> end;
            int startIndex, endIndex;
            for (int k = 0; k < planetCount; k++) // iterate over planets
            {
                if (planets[k].getName() == start) // is this the entry?
                    startIndex = k;
                else if (planets[k].getName() == end) // is this exit?
                    endIndex = k;
            }

/*
Djikstra's shortest path algorithm was chosen because it's faster than some,
easier to implement than some, and it's popular.
The code between the ****** finds the minimal distance, accounting for worm
holes, between the query planets.
***************************** begin djikstra's algo ****************************
*/
        // container for calculated shortest distances, accounting for portals
            int portalDiscounts[planetCount];
         // for tracking previously visited planets
            bool visited[planetCount];

            int tooFar = pow(10, 9); // or infinity
            // populate container for distances from origin
            for (int k = 0; k < planetCount; k++)
            {
                portalDiscounts[k] = tooFar; // default distance is too far
                // each planet has yet to be considered for route inclusion
                visited[k] = false;
            }

            portalDiscounts[startIndex] = 0; // distance from start to start

            // find the shortest distance from/to every planet
            for (int k = 0; k < planetCount - 1; k++)
            {
                // if a route exists, it's smaller than this
                int currentShortest = tooFar;
                // to help track the standing best route
                int shortestIndex;
                // iterate over every planet
                // cout << "shortest index before: " << shortestIndex << endl;
                for (int l = 0; l < planetCount; l++)
                {
                    if (        visited[l] == false && // not in route, yet
                        portalDiscounts[l] <= currentShortest) // is shortcut
                    {
                        currentShortest = portalDiscounts[l];
                        shortestIndex = l;
                    }
                }

                visited[shortestIndex] = true; // it's now part of the route

                // account for new route piece in relation to all planets
                for (int planet = 0; planet < planetCount; planet++)
                {
                    if (
                        // if this planet is not part of the route, yet
                        !visited[planet] &&
                        portalDiscounts[shortestIndex] +
                        distances[shortestIndex][planet] <
                        portalDiscounts[planet] // if this is a shortcut
                    )
                    {
                        // we have a new shortest route
                        portalDiscounts[planet] =
                            portalDiscounts[shortestIndex] +
                            distances[shortestIndex][planet];
                    }
                }
            }
//*************************** end djikstra's algo ******************************

            results += "The distance from " + start + " to " + end + " is " +
                       to_string(portalDiscounts[endIndex]) + " parsecs.\n";
        }
    }
    infile.close(); // close the input file
    ofstream outfile; // to record the results
    outfile.open(out); // open the output file
    outfile << results; // write the shortest paths to the output file
    outfile.close(); // close the output file

    return 0;
}
