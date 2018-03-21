# include <algorithm>
# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
# include "genBST.h"

using namespace std;

int main()
{
    ifstream kublaKhan;
    kublaKhan.open("kubla_khan.txt"); // access the input file
    string line;
    while (getline(kublaKhan, line)) // read every line
    {
        int length = line.size();
        for (int i = 0; i < length; i++) // remove punctuation from the line
        {
            if (ispunct(line[i])) // takes away hyphens, also
            {
                line.erase(i--, 1);
                length = line.size();
            }
        }
        stringstream lineStream(line);
        string word;
        while (lineStream >> word) // break the line into words
        {
            // make every letter lower case
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            cout << word << endl;
        }
    }

    return 0;
}
