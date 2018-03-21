/*******************************************************************************
This program calculates the area of a polygon.

This problem is from https://open.kattis.com/problems/convexpolygonarea

Title: Convex Polygon Area

For this problem, you just need to be able to calculate the area of convex
polygons.

Input
Input starts with an integer 1≤n≤100, indicating the number of convex polygons.
The next n lines each contain one convex polygon description. Each begins with
an integer 3≤m≤100 indicating the number of points in the polygon. Following
this are m pairs of integers, where each pair represents the x and
y coordinates of a vertex. The bounds on the coordinates are −5000≤x,y≤5000.
The vertices are given in counter-clockwise order, and no two vertices are
the same. As is typical for a polygon, the last vertex is connected to the
first one.

Output
For each polygon, output its area.

Sample Input 1	              Sample Output 1
2                             0.5
3 1 1 2 1 2 2                 52
4 0 0 10 0 13 5 10 8
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

float calculate_area(int pairs, vector<int> coords)
{
    int laces[pairs][2];
    int coords_index = 0;
    for (int i = 0; i < pairs; i++)
    {
        laces[i][0] = coords[coords_index];
        coords_index++;
        laces[i][1] = coords[coords_index];
        coords_index++;
    }

    int minuend = 0;
    int subtrahend = 0;
    // increase minuend
    for (int i = 0; i < pairs; i++)
    {
        minuend += laces[i][0] * laces[(i + 1) % pairs][1];
    }
    // increase subtrahend
    for (int i = 0; i < pairs; i++)
    {
        subtrahend += laces[i][1] * laces[(i + 1) % pairs][0];
    }

    return (0.5 * ((float)minuend - (float)subtrahend));
}

int main()
{
    vector<double> results;
    int polygons;
    cin >> polygons;
    for (int i = 0; i < polygons; i++)
    {
        int pairs;
        int num;
        vector<int> coords;
        cin >> pairs;
        for (int j = 0; j < pairs * 2; j++)
        {
            cin >> num;
            coords.push_back(num);
        }
        results.push_back(calculate_area(pairs, coords));
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}
