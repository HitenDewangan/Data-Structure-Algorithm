#include<iostream>
#include<vector>
using namespace std;


void helper(vector<vector<int>>& maze, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& vis) {
    int n = maze.size();
    // base case
    if(r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || vis[r][c] == true) {
        return; 
    }

    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;
    helper(maze, r+1, c, path+'D', ans, vis);
    helper(maze, r-1, c, path+'U', ans, vis);
    helper(maze, r, c-1, path+'L', ans, vis);
    helper(maze, r, c+1, path+'R', ans, vis);
    vis[r][c] = false;
    
}

// T.C. : O(4^(n*n)) in the worst case, as we can move in 4 directions at each cell
// S.C. : O(n*n) for the visited array and O(n*n) for
// optimization space : instead of using a visited array, we can mark the cell as 0 in the maze
// to indicate it has been visited, but this will modify the maze. So undo the changes after the recursion.


vector<string> findPaths(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(maze, 0, 0, path, ans, vis);

    return ans;

}


int main() {
    // Example Rat in a Maze problem
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    
    vector<string> paths = findPaths(maze);
    cout << "Possible paths from start to end:" << endl;    
    for (const string& path : paths) {
        cout << path << endl;
    }
    
    return 0;
}