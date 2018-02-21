/*******************************************************************************
This program duplicates rows and columns of matrices of characters.

This problem is from https://open.kattis.com/problems/skener

Title: Skener
Having solved the match issue, Mirko faced another challenging problem. His mom
ordered him to read an article about the newest couples on the Croatian
show-biz scene in the “Moja Tajna” magazine. The article is written in a very
small font size which Mirko cannot read. Luckily, Mirko has a scanner in the
closet which will enlarge the article for him.

The article is a matrix of characters with R rows and C columns. The characters
are letters of the English alphabet, digits and the character ‘.’ (period).
Mirko’s scanner supports two parameters, Zr and Zc. It substitutes each
character it scans with a matrix of Zr rows and Zc columns, where all entries
are equal to the scanned character.

Mirko realized his scanner’s software no longer works so he needs your help.

Input
The first row contains four integers, R, C, Zr and Zc. R and C are between
1 and 50, while Zr and Zc are between 1 and 5.

Each of the following R rows contains C characters each, representing the
article from “Moja Tajna”.

Output
The output should be a matrix of characters with R⋅Zr rows and C⋅Zc columns,
the enlarged article.

Sample Input 1	        Sample Output 1
3 3 1 2                 ..xx..
.x.                     xx..xx
x.x                     ..xx..
.x.

Sample Input 2	        Sample Output 2
3 3 2 1                 .x.
.x.                     .x.
x.x                     x.x
.x.                     x.x
                        .x.
                        .x.
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
This function adds columns to a row.
input: vector<string> matrix, the matrix to which columns are to be added.
       int addThisMany, the number of columns to add.
output: vector<string>, the new matrix with more columns.
*******************************************************************************/
vector<string> addColumns(vector<string> matrix, int addThisMany)
{
    for (int r = 0; r < matrix.size(); r++)
    {
        string oldRow = matrix[r];
        string newRow = "";

        // duplicate e'ry element addThisMany times
        for (int i = 0; i < oldRow.size(); i++)
        {
            for (int j = 0; j < addThisMany + 1; j++)
            {
                newRow += oldRow[i];
            }
        }
        matrix[r] = newRow;
    }
    return matrix;
}

/*******************************************************************************
This function adds rows to a matrix.
input: a matrix, i.e., a vector of strings, and
       an int, the number of rows to add to the matrix.
ouput: a new matrix, i.e., a vector of strings, with more rows.
*******************************************************************************/
vector<string> addRows(vector<string> matrix, int addThisMany)
{
    vector<string> newMatrix;
    // duplicate every row addThisMany times
    for (int r = 0; r < matrix.size(); r++)
    {
        for (int j = 0; j < addThisMany + 1; j++)
        {
            newMatrix.push_back(matrix[r]);
        }
    }
    return newMatrix;
}

int main()
{
    int row, column, zR, zC;
    cin >> row >> column >> zR >> zC;
    vector<string> matrix;
    for (int i = 0; i < row; i++)
    {
        string input;
        cin >> input;
        matrix.push_back(input);
    }

    // process the input matrix
    if (zR > 1)
    {
        matrix = addRows(matrix, zR - 1);
    }
    if (zC > 1)
    {
        matrix = addColumns(matrix, zC - 1);
    }

    // print the new matrix to the console
    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = 0; c < matrix[r].size(); c++)
        {
            cout << matrix[r][c];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
