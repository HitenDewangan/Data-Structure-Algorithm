
// ========================= Graph (Adjacency List Representation) ========================

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (visited.find(node) == visited.end()) { // not visited
            cout << node << " ";
            visited.insert(node);
            for (int neighbor : graph[node]) {
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(const vector<vector<int>>& graph, int node, unordered_set<int>& visited) {
    if (visited.find(node) == visited.end()) {
        cout << node << " ";
        visited.insert(node);
        for (int neighbor : graph[node]) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    int startNode = 0;

    cout << "BFS: ";
    bfs(graph, startNode);

    cout << "DFS: ";
    unordered_set<int> visited;
    dfs(graph, startNode, visited);
    cout << endl;

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