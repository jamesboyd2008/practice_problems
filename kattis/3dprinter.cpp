/*
This program, given a desired number of statues, outputs the minimal number
of days required to print those statues with a special 3D printer.

This problem is from https://open.kattis.com/problems/3dprinter

Title: 3D Printed Statues
You have a single 3D printer, and would like to use it to produce n statues.
However, printing the statues one by one on the 3D printer takes a long time,
so it may be more time-efficient to first use the 3D printer to print a new
printer. That new printer may then in turn be used to print statues or even
more printers. Print jobs take a full day, and every day you can choose for
each printer in your possession to have it print a statue, or to have it 3D
print a new printer (which becomes available for use the next day).

What is the minimum possible number of days needed to print at least n statues?

Input
The input contains a single integer n (1≤n≤10000), the number of statues you
need to print.

Output
Output a single integer, the minimum number of days needed to print at
least n statues.

Sample Input 1	Sample Output 1
1               1

Sample Input 2	Sample Output 2
5               4
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << ceil(log2(n)) + 1 << endl;

    return 0;
}
