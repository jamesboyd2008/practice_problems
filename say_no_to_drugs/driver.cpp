#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "genBST.h"
#include "Kubla.h"

using namespace std;

void fillTree(BST<Kubla> &tree);
void printTree(BST<Kubla> &tree);

int main()
{
    BST<Kubla> kublasKhans;
    fillTree(kublasKhans);
    printTree(kublasKhans);
    return 0;
}

void fillTree(BST<Kubla> &tree)
{
    ifstream kublaKhan;
    kublaKhan.open("kubla_khan.txt"); // access the input file
    string line;
    int lineNum = 1; // line 1 reads: "Kubla Khan"
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
            // cout << word << endl;
            set<int> nums;
            Kubla kubla(word, nums);
            Kubla* doesItExist = new Kubla;
            doesItExist = tree.search(kubla);
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
        lineNum++;
    }
}

void printTree(BST<Kubla> &tree)
{
    /*
    After you finish looping through the file, iterate through the tree in alphabetical order (i.e. an inorder
traversal) and print each node. This will consist of printing the word and its list of line number
occurrences.
    */
    tree.inorder();
    // tree.postorder();
    // tree.preorder();
}
