// get name of file to be spell checked as single arg
// go through each word, one at at time
// see if its in your dictionary -- linear search
    // if it is, move on to next word
    // if it isn't, add it to the collection of words that are mispelled
        // maybe add it's location to output, as well
            // location is line number and character count
                // get this from something else

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    ifstream infile;
    ofst
    infile.open("dictionary.txt");
    string line;
    while(getline(infile, line))
    {
        // getline(infile, line);
        // allcaps line
        words.push_back(line);
    }

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }

    return 0;
}
