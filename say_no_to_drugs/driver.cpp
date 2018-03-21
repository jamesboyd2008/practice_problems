#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "genBST.h"
#include "Kubla.h"

using namespace std;

void fillTree(BST<Kubla> &tree); // forward declaration
void printTree(BST<Kubla> &tree); // forward declaration

int main()
{
    /* Instantiate a binary search tree, the nodes of which being comprised,
    in part, of objects that contain the words of a poem and the line numbers
    upon which they appear. */
    BST<Kubla> kublasKhans;
    fillTree(kublasKhans); // populate the tree with poem data
    printTree(kublasKhans); // print the tree to the console
    return 0;
}
/*
This function, taking a refernce to a binary search tree of type <Kubla> as
the single parameter, parses over a poem, upon which this function is
dependent, populates the tree with data, and returns nothing.  The data is the
words of the poem, downcased and stripped of most punctuation, and the line
numbers upon which the words appear.
*/
void fillTree(BST<Kubla> &tree)
{
    ifstream kublaKhan;
    kublaKhan.open("kubla_khan.txt"); // access the poem
    string line;
    int lineNum = 1; // line 1 reads: "Kubla Khan"
    while (getline(kublaKhan, line)) // read every line
    {
        int length = line.size();
        for (int i = 0; i < length; i++) // remove punctuation from the line
        {
            if (ispunct(line[i])) // takes away hyphens, also.
            {
                line.erase(i--, 1);  // remove the character from the line
                length = line.size(); // account for the shorter line length
            }
        }
        stringstream lineStream(line); // for removing whitespace
        string word; // a <string> is needed to make a Kubla
        while (lineStream >> word) // break the line into words
        {
            // make every letter lower case
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            set<int> nums; // a <set> is needed to make a Kubla
            Kubla kubla(word, nums); // these attributes will be updated, below
            Kubla* doesItExist = new Kubla; // for holding search results
            doesItExist = tree.search(kubla); // find the word in the tree
            if (doesItExist == NULL) // if the word isn't in the tree
            {
                kubla.addLineNumber(lineNum); // add line number to the word
                tree.insert(kubla); // put word in the tree
            }
            else // the word is already in the tree
            {
                doesItExist->addLineNumber(lineNum); // add number to the set
            }
        }
        lineNum++; // keep track of the line upon which the words appear
    }
}
/*
This function, taking a refernce to a binary search tree of type <Kubla> as
the single parameter, prints every node to the console, and returns nothing.
*/
void printTree(BST<Kubla> &tree)
{
    tree.inorder();
}
