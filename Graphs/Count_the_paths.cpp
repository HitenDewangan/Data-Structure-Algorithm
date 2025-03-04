// https://www.geeksforgeeks.org/problems/count-the-paths4332/0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        int bfs(const vector<vector<int>>& adj, int start, int destination) {
            queue<int> q;
            q.push(start);
            int count = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : adj[current]) {
                    if (neighbor == destination) {
                        count++;
                    }
                    else {
                        q.push(neighbor);
                    }
                }
            }

            return count;
        }
        void dfs(const vector<vector<int>>& adj, int current, int destination, int& count) {
            if (current == destination) {
                count++;
                return;
            }

            for (int neighbor : adj[current]) {
                dfs(adj, neighbor, destination, count);
            }
        }

        int possible_paths(vector<vector<int>> &edges, int n, int start, int destination) {
            vector<vector<int>> adj(n);
            for (auto edge : edges) {
                adj[edge[0]].push_back(edge[1]); // directed graph
            }

            int count = 0;
            cout << bfs(adj, start, destination) << endl;
            dfs(adj, start, destination, count);
            return count;
        }
};

int main() {
// [[0,1],[0,3],[2,0],[2,1],[1,3]]
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {2, 0},
        {2, 1},
        {1, 3}
    };

    int n = 4;
    int start = 2;
    int destination = 3;

    Solution solution;
    cout << solution.possible_paths(edges, n, start, destination) << endl;

    return 0;
}