/* This program determines how many CD's Jack and Jill both own.

From https://open.kattis.com/problems/cd

Title: 
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