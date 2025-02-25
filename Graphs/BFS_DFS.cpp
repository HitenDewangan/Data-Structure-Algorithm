
// ========================= Graph (Adjacency List Representation) ========================

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

void bfs(const vector<vector<int>>& adj, int start) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(const vector<vector<int>>& adj, int start) {
    stack<int> s;
    unordered_set<int> visited;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (visited.find(current) == visited.end()) {
            cout << current << " ";
            visited.insert(current);

            for (int i = adj[current].size() - 1; i >= 0; --i) { // Reverse to get left most first.
                int neighbor = adj[current][i];
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    int startNode = 0;

    bfs(adj, startNode);
    dfs(adj, startNode);

    return 0;
}

/*
Graph Connections :
------------------
0: 1, 2
1: 0, 3, 4
2: 0, 5
3: 1
4: 1
5: 2

      0
     / \
    1   2
   / \   \
  3   4   5

BFS: Explores the graph level by level, finding the shortest path in an unweighted graph.
DFS: Explores as far as possible along each branch before backtracking.
*/