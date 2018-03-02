/*******************************************************************************
This program tells you how many B's and A's are on a screen of B's and A's.

This problem is from https://open.kattis.com/problems/rijeci

Title: Riječi
One day, little Mirko came across a funny looking machine! It consisted of a
very very large screen and a single button. When he found the machine, the
screen displayed only the letter A. After he pressed the button, the letter
changed to B. The next few times he pressed the button, the word transformed
from B to BA, then to BAB, then to BABBA... When he saw this, Mirko realized
that the machine alters the word in a way that all the letters B get
transformed to BA and all the letters A get transformed to B.

Amused by the machine, Mirko asked you a very difficult question!
After K times of pressing the button, how many letters A and how much letters
B will be displayed on the screen?

Input
The first line of input contains the integer K (1≤K≤45), the number of
times Mirko pressed the button.

Output
The first and only line of output must contain two space-separated integers,
the number of letters A and the number of letter B.

Sample Input 1	Sample Output 1
1               0 1

Sample Input 2	Sample Output 2
4               2 3

Sample Input 3	Sample Output 3
10              34 55
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int presses;
    cin >> presses;

    // string oldScreen = "A",
    //        newScreen = "" ;
    // for (int i = 0; i < presses; i++)
    // {
    //     for (int j = 0; j < oldScreen.size(); j++)
    //     {
    //         if (oldScreen[j] == 'A')
    //         {
    //             newScreen += "B";
    //         } else {
    //             newScreen += "BA";
    //         }
    //     }
    //     oldScreen = newScreen;
    //     newScreen = "";
    // }

    // The approach above was abandoned because of slowness.
    // Noticing that the new chunk added is the whole chunk from two prior...
    /*
    0  1  1    B
    1  1  2    BA
    1  2  3    BAB
    2  3  5    BABBA
    3  5  8    BABBABAB
    5  8  13   BABBABABBABBA
    8  13 21   BABBABABBABBABABBABAB
    12 21 34   BABBABABBABBABABBABABBABBABABBABBA
    21 34 55   BABBABABBABBABABBABABBABBABABBABBABABBABABBABBABABBABAB
    */

    // string first = "B",
    //        second = "BA",
    //        third = "BAB";
    //
    // if (presses == 1)
    // {
    //     third = first;
    // } else if (presses == 2)
    // {
    //     third = second;
    // } else {
    //     for (int i = 2; i < presses; i++)
    //     {
    //         third = second + first;
    //         first = second;
    //         second = third;
    //     }
    // }
    //
    //
    // int aS, bS;
    // aS = bS = 0;
    //
    // for (int i = 0; i < third.size(); i++)
    // {
    //     if (third[i] == 'A')
    //         aS++;
    //     else
    //         bS++;
    // }
    // cout << third << endl;
    // cout << aS << " " << bS << endl;

    // The second approach from above was too slow, as well. After noticing
    // fibonacci numbers occuring as the values of the A and B totals...

    int first  =  0,
        second = 1,
        third;

    if (presses > 1)
    {
        for (int i = 1; i < presses; i++)
        {
            third = first + second;
            first = second;
            second = third;
        }
    }

    cout << first << " " << second << endl;

    return 0;
}
