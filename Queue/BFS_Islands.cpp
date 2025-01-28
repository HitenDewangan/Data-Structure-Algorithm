#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int x;
    int y;
};

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    queue<Node> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                // Mark as visited to avoid revisiting
                grid[i][j] = '0';

                // Start BFS from this island
                q.push({i, j});

                while (!q.empty()) {
                    Node top = q.front();
                    q.pop();

                    // Explore neighboring '1' nodes in all directions
                    if (top.x + 1 < m && grid[top.x + 1][top.y] == '1') {
                        grid[top.x + 1][top.y] = '0';
                        q.push({top.x + 1, top.y});
                    }
                    if (top.x - 1 >= 0 && grid[top.x - 1][top.y] == '1') {
                        grid[top.x - 1][top.y] = '0';
                        q.push({top.x - 1, top.y});
                    }
                    if (top.y + 1 < n && grid[top.x][top.y + 1] == '1') {
                        grid[top.x][top.y + 1] = '0';
                        q.push({top.x, top.y + 1});
                    }
                    if (top.y - 1 >= 0 && grid[top.x][top.y - 1] == '1') {
                        grid[top.x][top.y - 1] = '0';
                        q.push({top.x, top.y - 1});
                    }
                }

                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '1'},
        {'0', '1', '0', '1', '1'}
    };

    int totalIslands = numIslands(grid);
    cout << "Number of islands: " << totalIslands << endl;

    vector<vector<char>> grid2 = {
        {'1', '0', '0', '1', '0'},
        {'0', '0', '1', '1', '0'},
        {'1', '0', '1', '0', '1'},
        {'1', '0', '0', '1', '1'}
    };
    
    int total = numIslands(grid2);
    cout << "Number of islands: " << total << endl;

    vector<vector<char>> grid3 = {
        {'0', '0', '1', '0', '0'},
        {'1', '1', '0', '1', '0'},
        {'0', '1', '1', '0', '1'},
        {'1', '0', '0', '1', '0'},
        {'1', '1', '1', '1', '1'}
    };
    
    int total3 = numIslands(grid3);
    cout << "Number of islands: " << total3 << endl;

    return 0;
}

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

/* Descriptions : How the code is solved

Logic : 

    1. Start BFS from all '1' nodes and mark them as visited
    2. Count the number of islands

*/
