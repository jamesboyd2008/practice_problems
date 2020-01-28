/* This program determines how many CD's Jack and Jill both own.

From https://open.kattis.com/problems/cd

Title: CD
Jack and Jill have decided to sell some of their Compact Discs, while they still have some value. They have decided to sell one of each of the CD titles that they both own. How many CDs can Jack and Jill sell?

Neither Jack nor Jill owns more than one copy of each CD.

Input
The input consists of a sequence of test cases. The first line of each test case contains two positive integers 𝑁 and 𝑀, each at most one million, specifying the number of CDs owned by Jack and by Jill, respectively. This line is followed by 𝑁 lines listing the catalog numbers of the CDs owned by Jack in increasing order, and 𝑀 more lines listing the catalog numbers of the CDs owned by Jill in increasing order. Each catalog number is a positive integer no greater than one billion. The input is terminated by a line containing two zeros. This last line is not a test case and should not be processed.

Output
For each test case, output a line containing one integer, the number of CDs that Jack and Jill both own.

Sample Input 1:
3 3
1
2
3
1
2
4
0 0

Sample Output 1:
2

*/
#include <iostream>

using namespace std;

int main() {
    int jackTot, jillTot;
    cin >> jackTot >> jillTot;
    do{
        bool billion[1000000001] = {}; // seg fault 11

        int common = 0;

        int catalogNum;
        for(int i = 0; i < jackTot; i++) {
            cin >> catalogNum;
            billion[catalogNum] = true;
        }

        for(int j = 0; j < jillTot; j++) {
            cin >> catalogNum;
            if(billion[catalogNum] == true) {
                common++;
            }
        }

        cout << common << endl;
        cin >> jackTot >> jillTot;

    } while (!(jackTot == 0 && jillTot == 0));

    return 0;
}