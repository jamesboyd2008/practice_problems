/*******************************************************************************
This is the Kubla class, which is the type of object making up the nodes of the
binary search tree in driver.cpp
*******************************************************************************/

#include <iterator>
#include <set>
#include <string>

using namespace std;

#ifndef KUBLA
#define KUBLA

class Kubla
{
public:
    Kubla() { word = ""; } // default constructor
    Kubla(string inputWord, set<int> lineNums) // overloaded constructor
    {
        word = inputWord;
        lines = lineNums;
    }
    void addLineNumber(int num);
    bool operator==(const Kubla& word) const;
    bool operator<(const Kubla& word) const;
    bool operator>(const Kubla& word) const;
    friend ostream& operator<<(ostream& out, Kubla& kubla);
private:
    string word; // the word
    set<int> lines; // the line numbers upon which the word appears
};
// add a line number to the object, avoiding duplicates
void Kubla::addLineNumber(int num)
{
    lines.insert(num);
}
// see if two words are the same
bool Kubla::operator==(const Kubla& kubla) const
{
    return kubla.word.compare(word) == 0;
}
// see if one word precedes another, alphabetically
bool Kubla::operator<(const Kubla& kubla) const
{
    return kubla.word.compare(word) > 0;
}
// see if one word comes after another, alphabetically
bool Kubla::operator>(const Kubla& kubla) const
{
    return kubla.word.compare(word) < 0;
}
// for printing the word and the lines upon which it appears to the console
ostream& operator<<(ostream& out, Kubla& kubla)
{
    out << kubla.word;
    set<int>::iterator itr;
    for (itr = kubla.lines.begin(); itr != kubla.lines.end(); ++itr)
    {
        out << " " << *itr;
    }
    out << endl;
    return out;
}


#endif
