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
    int  *positionInRow, howMany, configurationsExamined;
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
    // initialize board with zero solutions discovered
    // and zero configurations examined.
    howMany = configurationsExamined = 0;
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
                if (row % 2 == 0) {
                    if (col % 2 == 0) {
                        // white squares get a "."
                        out << ". ";
                    } else {
                        // black squares get an "x"
                        out << "x ";
                    }
                } else {
                    if (col % 2 == 0) {
                        out << "x ";
                    } else {
                        out << ". ";
                    }
                }
            }
        }
        out << endl;
    }
    out << endl;
}
void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++) {
        if (column[col] == available &&
            leftDiagonal [row+col] == available &&
            rightDiagonal[row-col+norm] == available) {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;
            // increment board configurations examined,
            // if still working on the first solution.
            if (howMany < 1)
                configurationsExamined++;
            if (row < squares-1) {
                putQueen(row+1);
            } else {
                // The condition below ensures only the first solution is
                // displayed.
                if (howMany < 1) {
                    printBoard(cout);
                }
                howMany++; // increment solutions discovered
            }
            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        } else {
            // increment board configurations examined,
            // if still working on the first solution.
            if (howMany < 1)
                configurationsExamined++;
        }
        // comment out the code block below to find more solutions.
        if (howMany > 0) {
            break;
        }
    }
}
void ChessBoard::findSolutions() {
    putQueen(0);
    // Tell the user how many solutions were found.
    // cout << howMany << " solutions were found.\n";
    // Tell the user how many board configurations were examined
    // before a board configuration was examined that happened to be a solution.
    cout << configurationsExamined - 1
         << " board configuarations were examined, \n"
         << "prior to the discovery of the first solution.\n";
}
// This function tests the rest of the program.
// It creates boards with sizes 4-10 and finds solutions for them.
void runTests() {
    ChessBoard board4(4),
               board5(5),
               board6(6),
               board7(7),
               board8,
               board9(9),
               board10(10);
    ChessBoard boards[7] = {
        board4,
        board5,
        board6,
        board7,
        board8,
        board9,
        board10
    };
    for (int i = 0; i < 7; i++) {
        boards[i].findSolutions();
    }
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

    // runTests(); // uncomment to run tests

    return 0;
}
