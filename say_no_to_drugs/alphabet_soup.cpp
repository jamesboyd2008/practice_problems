#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "genBST.h"
#include "Kubla.h"

using namespace std;

void fillTree();
void printTree();

int main()
{
    fillTree();
    printTree();
    return 0;
}

void fillTree()
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
}

void printTree()
{
    /*
    After you finish looping through the file, iterate through the tree in alphabetical order (i.e. an inorder
traversal) and print each node. This will consist of printing the word and its list of line number
occurrences.
    */
}
