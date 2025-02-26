#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0';
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int nr = grid.size();
    int nc = grid[0].size();
    int num_islands = 0;

    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++num_islands;
                dfs(grid, r, c);
            }
        }
    }

    return num_islands;
}

int main() {
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << "Number of islands in grid1: " << numIslands(grid1) << endl; // Output: 1

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of islands in grid2: " << numIslands(grid2) << endl; // Output: 3

    return 0;
}