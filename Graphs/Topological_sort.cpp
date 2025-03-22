#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> inDegree(numVertices, 0);
    vector<int> result;

    // Calculate in-degrees
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numVertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check for cycles
    if (result.size() != numVertices) {
        return {}; // Cycle detected, topological sort not possible
    }

    return result;
}

int main() {
    // Example graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {4},
        {}
    };

    vector<int> sorted = topologicalSort(graph);

    if (sorted.empty()) {
        cout << "Graph contains a cycle, topological sort not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int vertex : sorted) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    //Example graph with cycle.
    vector<vector<int>> graph2 = {
        {1},
        {2},
        {0}

    };

    sorted = topologicalSort(graph2);

    if (sorted.empty()) {
        cout << "Graph contains a cycle, topological sort not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int vertex : sorted) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}