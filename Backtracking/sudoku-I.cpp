#include <iostream>
using namespace std;

// Size of the Sudoku grid
const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
            if ((col + 1) % 3 == 0 && col != N-1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row != N-1) {
            cout << "------+-------+------" << endl;
        }
    }
}

// Function to check if a number can be placed in the given cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number exists in the current row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }
    
    // Check if the number exists in the current column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }
    
    // Check if the number exists in the current 3x3 box
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxStartRow + i][boxStartCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    
    // Find the first empty cell (marked with 0)
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    
    // If no empty cell found, puzzle is solved
    if (!isEmpty) {
        return true;
    }
    
    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assign the number if it's safe
            grid[row][col] = num;
            
            // Recursively solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }
            
            // If recursion fails, backtrack
            grid[row][col] = 0;
        }
    }
    
    // Trigger backtracking
    return false;
}

// T.C. : O(9^(N*N)) in the worst case, as we try all numbers for each empty cell
// S.C. : O(N*N) for the recursion stack and the grid storage
// This code solves a Sudoku puzzle using backtracking.

int main() {
    // Example Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
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
    
    cout << "Original Sudoku:" << endl;
    printGrid(grid);
    cout << "\nSolving...\n" << endl;
    
    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku." << endl;
    }
    
    return 0;
}