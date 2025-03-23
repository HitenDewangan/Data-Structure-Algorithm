#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, graph)) {
                return true; // Cycle found in subtree
            }
        } else if (neighbor != parent) {
            return true; // Cycle found (back edge)
        }
    }
    return false; // No cycle found
}

bool hasCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, graph)) {
                return true; // Cycle found in component
            }
        }
    }
    return false; // No cycle found in any component
}

// ----------------------- Example Usage ---------------------------------

int main() {
    vector<vector<int>> graph = {{1, 2}, {2}, {0, 3}, {3}};

    if (hasCycle(graph)) {  
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}