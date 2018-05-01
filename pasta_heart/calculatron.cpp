#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
    // dynamic arrays
    int *dArray;
    // int sizey;

    // construct adjacency matrix from input using distance formula a bunch
    // d(P_1, P_2) = sqrt( (x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2 )
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
        results += "Case " + to_string(i) + ":\n";
        infile >> planetCount; // receive quantity of planets within test case i
        for (int j = 0; j < planetCount; j++) // for each planet...
            infile >> name >> x >> y >> z; // get coords
        infile >> portalCount; // receive quantity of worm holes
        for (int j = 0; j < portalCount; j++)
        {
            // make the distance between these two planets a big ol' 0
            infile >> enterPortal >> exitPortal;
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


    // if there are no black holes, it's a straight shot
    // else (there are black holes)
        // if the distance to one or more black holes,
        // followed by the destination is shorter,
            // go that way
        // else
            // it's a straight shot



    return 0;
}
