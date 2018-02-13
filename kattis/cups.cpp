/******************************************************************************
This program, given cup radius and color data, outputs the best way to stack 
them.

This problem is from: https://open.kattis.com/problems/cups

Title: Stacking Cups

You are programming a cup stacking module for your robot. This robot is 
equiped with several sensors that can accurately determine the radius and 
color of a cup. The problem is that there is a glitch in the robot’s core 
that processess sensor inputs so the radius is doubled, if the result of 
the color sensor arrives to the routine after the radius.
For instance, for a red cup with a radius of 5 units, your module will 
receive either “red 5” or “10 red” message.

Given a list of messages from the core routine, each describing a different 
cup, can you put the cups in order of the smallest to the largest?

Input
The first line of the input file contains an integer N, the number of 
cups (1≤N≤20). Next N lines will contain two tokens each, either as 
“color radius” or “diameter color”. The radius of a cup R will be a positive 
integer less than 1000. The color of a cup C will be a non-empty string of 
lower case English letters of length at most 20. All cups will be different 
in both size and color.

Output
Output colors of cups, one color per line, in order of increasing radius.

Sample Input 1	   Sample Output 1
3                  blue
red 10             green 
10 blue            red
green 7
*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> colors;
    vector<int> radii;
    int quantity;
    cin >> quantity;
    cin.ignore();
    
    for (int i = 0; i < quantity; i++)
    {
        string cupData;
        string first, second, color;
        int radius;
        cin >> first >> second;
        if (first[0] >= 48 && first[0] <= 57)
        {
            radius = stoi(first) / 2;
            color = second;
        }
        else
        {
            color = first;
            radius = stoi(second);
        }
        colors.push_back(color);
        radii.push_back(radius);
    }
    bool keepGoing = true;
    while (keepGoing)
    {
        bool changeMade = false;
        for (int i = 0; i < radii.size() - 1; i++)
        {
            if (radii[i] > radii[i + 1])
            {
                int temp = radii[i + 1];
                radii[i + 1] = radii[i];
                radii[i] = temp;
                string focalColor = colors[i + 1];
                colors[i + 1] = colors[i];
                colors[i] = focalColor;
                changeMade = true;
            }
        }
        if (changeMade == false)
        {
            keepGoing = false;
        }
    }
    for (int i = 0; i < colors.size(); i++)
    {
        cout << colors[i] << "\n";
    }
    return 0;
}
