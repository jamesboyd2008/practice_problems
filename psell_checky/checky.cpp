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
    ofstream outfile;
    infile.open("dictionary.txt");
    outfile.open("dictionary_caps.txt");
    string line;
    while(getline(infile, line))
    {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        words.push_back(line);
    }

    for (int i = 0; i < words.size(); i++)
    {
        outfile << words[i] << endl;
    }
    infile.close();
    outfile.close();

    return 0;
}
