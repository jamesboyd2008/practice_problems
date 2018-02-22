/*******************************************************************************
This program determines who scored the highest, guessing on a multiple choice
test.

This problem is from https://open.kattis.com/problems/ptice

Title: Ptice
Adrian, Bruno and Goran wanted to join the bird lovers’ club. However, they did
not know that all applicants must pass an entrance exam. The exam consists of
N questions, each with three possible answers: A, B and C.

Unfortunately, they couldn’t tell a bird from a whale so they are trying to
guess the correct answers. Each of the three boys has a theory of what set
of answers will work best:

Adrian claims that the best sequence is: A, B, C, A, B, C, A, B, C, A, B, C ...

Bruno is convinced that this is better: B, A, B, C, B, A, B, C, B, A, B, C ...

Goran laughs at them and will use this
sequence: C, C, A, A, B, B, C, C, A, A, B, B ...

Write a program that, given the correct answers to the exam, determines who of
the three was right – whose sequence contains the most correct answers.

Input
The first line contains an integer N (1≤N≤100), the number of questions
on the exam.

The second line contains a string of N letters ‘A’, ‘B’ and ‘C’. These are,
in order, the correct answers to the questions in the exam.

Output
On the first line, output M, the largest number of correct answers one of the
three boys gets.

After that, output the names of the boys (in alphabetical order) whose
sequences result in M correct answers.

Sample Input 1	     Sample Output 1
5                    3
BAACC                Bruno



Sample Input 2	     Sample Output 2
9                    4
AAAABBBBB            Adrian
                     Bruno
                     Goran
*******************************************************************************/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int questionCount;
    cin >> questionCount;
    string answers;
    cin >> answers;

    int adrianScore, brunoScore, goranScore;
    adrianScore = brunoScore = goranScore = 0;
    string adrianAns = "ABC",
           brunoAns  = "BABC",
           goranAns  = "CCAABB";
    int aSize = adrianAns.size();
    int bSize = brunoAns.size();
    int goSize = goranAns.size();

    for (int i = 0; i < answers.size(); i++)
    {
        // python style modulus ==> (b + (a%b)) % b
        if (answers[i] == adrianAns[(aSize + (i % aSize)) % aSize])
        {
            adrianScore++;
        }
        if (answers[i] == brunoAns[(bSize + (i % bSize)) % bSize])
        {
            brunoScore++;
        }
        if (answers[i] == goranAns[(goSize + (i % goSize)) % goSize])
        {
            goranScore++;
        }
    }

    // see who has highest score
    int scores[3] = { adrianScore, brunoScore, goranScore };
    string names[3] = { "Adrain", "Bruno", "Goran" };
    int* highScore = max_element(scores, scores+3);
    cout << *highScore << endl;
    for (int i = 0; i < 3; i++)
    {
        if (scores[i] == *highScore)
        {
            cout << names[i] << endl;
        }
    }

    return 0;
}
