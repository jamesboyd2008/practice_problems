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
input: string, the row to which columns must be added
output: string, the new row, with more columns
*******************************************************************************/
string addColumns(string row, int addThisMany)
{
    // duplicate e'ry element addThisMany times
    int originalSize = row.size();
    for
    (
        int i = 0;
        i < originalSize * (addThisMany + 1) - (addThisMany - 1);
        i += addThisMany + 1
    )
    {
        // insert another i into row right after i
        row.insert((i + 1), &row[i]);
    }

    return row;
}

/*******************************************************************************
This function adds rows to a matrix.
input: a matrix, i.e., a vector of vectors of ints, and
       an int, the number of rows to add to the matrix.
ouput: a new matrix, i.e., a vector of vectors of ints, with more rows.
*******************************************************************************/
vector<string> addRows(vector<string> matrix, int addThisMany)
{


    return matrix;
}

int main()
{
    int row, column, zR, zC;
    cin >> row >> column >> zR >> zC;
    vector<string> matrix;
    for (int i = 0; i < row; i++)
    {
        // cout << "Let's get a row\n";
        string input;
        cin >> input;
        // matrix[i] = input;
        matrix.push_back(input);
    }

    // process the input matrix
    if (zR > 1)
    {
        matrix = addRows(matrix, zR);
    }
    if (zC > 1)
    {
        // matrix = addColumns(matrix, zC - 1);
        for (int r = 0; r < row; r++)
        {
            matrix[r] = addColumns(matrix[r], zC - 1);
        }
    }

    // print the new matrix to the console
    for (int r = 0; r < (row * zR); r++)
    {
        for (int c = 0; c < (column * zC); c++)
        {
            cout << matrix[r][c];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
