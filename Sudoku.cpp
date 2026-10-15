#include <iostream>
using namespace std;
int sudoku[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num)
            return false;
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == num)
                return false;
        }
    }
    return true;
}
bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        sudoku[row][col] = num;
                        if (solveSudoku())
                            return true;
                        sudoku[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    cout << "Original Sudoku:\n";
    printSudoku();
    if (solveSudoku()) {
        cout << "\nSolved Sudoku:\n";
        printSudoku();
    } else {
        cout << "\nNo solution exists.\n";
    }
    return 0;
}

