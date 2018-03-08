/*******************************************************************************
This program is an implementation of the classic N Queens problem.

A user is prompted for a number, N, which represents the length and width of a
chess board.  The program then calculates and outputs the number of ways
N queens can be arranged on the board such that no queen threatens another.
The program also outputs the first solution in a readable fashion.

Here's a more thorough explanation:
https://en.wikipedia.org/wiki/Eight_queens_puzzle
*******************************************************************************/

#include <iostream>

using namespace std;

class ChessBoard {
public:
    ChessBoard();    // 8 x 8 chessboard;
    ChessBoard(int); // n x n chessboard;
    void findSolutions();
private:
    const bool available;
    const int squares, norm;
    bool *column, *leftDiagonal, *rightDiagonal;
    // howMany is used to track the total number of solutions discovered.
    int  *positionInRow, howMany;
    void putQueen(int);
    void printBoard(ostream&);
    void initializeBoard();
};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1) {
    initializeBoard();
}
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
    initializeBoard();
}
void ChessBoard::initializeBoard() {
    int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal  = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];
    for (i = 0; i < squares; i++)
        positionInRow[i] = -1;
    for (i = 0; i < squares; i++)
        column[i] = available;
    for (i = 0; i < squares*2 - 1; i++)
        leftDiagonal[i] = rightDiagonal[i] = available;
    howMany = 0; // initialize board with zero solutions discovered, so far.
}
void ChessBoard::printBoard(ostream& out) {
    // ♛
    // ─ │ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼ // light
    for (int row = 0; row < squares; row++) {
        for (int col = 0; col < squares; col++) {
            // This condition checks whether a queen is on the square.
            if (positionInRow[row] == col) {
                out << "♛ ";
            } else {
                // Determine the color of the unoccupied square.

                out << "_ ";
            }
        }
        out << endl;
    }
    out << endl;
}
void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++)
        if (column[col] == available &&
            leftDiagonal [row+col] == available &&
            rightDiagonal[row-col+norm] == available) {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;
            if (row < squares-1)
                putQueen(row+1);
            else {
                // The condition below ensures only the first solution is
                // displayed.
                if (howMany < 1)
                    printBoard(cout);
                howMany++; // increment solutions discovered
            }
            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        }
}
void ChessBoard::findSolutions() {
    putQueen(0);
    // Tell the user how many solutions were found.
    cout << howMany << " solutions found.\n";
}

int main() {
    // This loop allows a user to try out different values for N
    // without ending the program.
    while (true) {
        int n;
        cout << "Enter a value for N between 4 and 10: ";
        cin >> n;
        // The condition below ensures that n is between 4 and 10.
        if (4 <= n && n <= 10) {
            ChessBoard board(n);
            board.findSolutions();
        } else {
            cout << "That value is not between 4 and 10.\n";
        }
        char response;
        // Prompt the user to input whether they want another go.
        cout << "Would you like to enter another value for N? (y/n): ";
        cin >> response;
        if (response != 'y')
            break;
    }
    return 0;
}
