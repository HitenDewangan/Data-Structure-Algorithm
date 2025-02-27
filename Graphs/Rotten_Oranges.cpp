
// ==================== Multisource BFS ====================
// T.C: O(N*M)
// S.C: O(N*M)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to check if a cell is valid
bool isValid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> rotten;
    int freshCount = 0;

    // Initialize the queue with rotten oranges and count fresh oranges
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rotten.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if(freshCount == 0) return 0; // if no fresh oranges, no time passes.

    int minutes = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    while (!rotten.empty()) {
        int size = rotten.size();
        bool anyRotten = false; // Check if any fresh orange was rotten in this minute.

        for (int i = 0; i < size; ++i) {
            pair<int, int> current = rotten.front();
            rotten.pop();

            for (const auto& dir : directions) {
                int newRow = current.first + dir.first;
                int newCol = current.second + dir.second;

                if (isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // Rot the fresh orange
                    rotten.push({newRow, newCol});
                    freshCount--;
                    anyRotten = true;
                }
            }
        }
        if(anyRotten) minutes++; // only increment the minutes if something was rotten.
    }

    if (freshCount > 0) {
        return -1; // Some fresh oranges are still left
    }

    return minutes;
}

int main() {
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Minutes to rot all oranges: " << orangesRotting(grid1) << endl; // Output: 4

    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << "Minutes to rot all oranges: " << orangesRotting(grid2) << endl; // Output: -1

    vector<vector<int>> grid3 = {{0, 2}};
    cout << "Minutes to rot all oranges: " << orangesRotting(grid3) << endl; //output: 0

    vector<vector<int>> grid4 = {{1,2,0,1,1,0,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    cout << "Minutes to rot all oranges: " << orangesRotting(grid4) << endl;

    return 0;
}