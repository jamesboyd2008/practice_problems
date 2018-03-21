/********************************************************************************************
This is the Kubla class, which is the type of object making up the binary search tree
in alphabet_soup.cpp
********************************************************************************************/

#include <iterator>
#include <set>
#include <string>

using namespace std;

#ifndef KUBLA
#define KUBLA

class Kubla
{
public:
    Kubla()
    {
        word = "";
    }
    Kubla(string inputWord, set<int> lineNums)
    {
        word = inputWord;
        lines = lineNums;
    }
    void addLineNumber(int num);
    bool operator==(const Kubla& word) const;
    bool operator<(const Kubla& word) const;
    bool operator>(const Kubla& word) const;
    // print the word and the lines upon which appears to the console
    friend ostream& operator<<(ostream& out, Kubla& kubla)
    {
        out << kubla.word;
        set<int>::iterator itr;
        for (itr = kubla.lines.begin(); itr != kubla.lines.end(); ++itr)
        {
            out << '\t' << *itr;
        }
        out << endl;
        return out;
    }
private:
    string word;
    set<int> lines;
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

#endif
