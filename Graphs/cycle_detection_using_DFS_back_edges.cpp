#include <iostream>
#include <vector>

using namespace std; 

// Function to perform DFS and detect cycle in a directed graph using recursion stack

bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& graph) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : graph[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, graph)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[v] = false; // Remove the vertex from recursion stack
    return false;
}

bool isCyclic(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<bool> recStack(numVertices, false);

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && isCyclicUtil(i, visited, recStack, graph)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Example graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},
        {2},
        {0, 3},
        {3}
    };

    if (isCyclic(graph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    // Example graph with a cycle
    vector<vector<int>> graphWithCycle = {
        {1},
        {2},
        {0}
    };

    if (isCyclic(graphWithCycle)) {
        cout << "Graph with cycle contains a cycle." << endl;
    } else {
        cout << "Graph with cycle does not contain a cycle." << endl;
    }

    // Graph from the image (0-based indexing)
    vector<vector<int>> newgraph = {
        {1, 5},     // Node 1 (0): 2, 6
        {0, 3, 2},  // Node 2 (1): 1, 4, 3
        {1, 9},     // Node 3 (2): 2, 10
        {1, 7, 10}, // Node 4 (3): 2, 8, 11
        {5, 10},    // Node 5 (4): 6, 11
        {0, 4, 9},  // Node 6 (5): 1, 5, 10
        {8, 9},     // Node 7 (6): 9, 10
        {3, 8},     // Node 8 (7): 4, 9
        {6, 7},     // Node 9 (8): 7, 8
        {2, 5, 6},  // Node 10 (9): 3, 6, 7
        {3, 4}      // Node 11 (10): 4, 5
    };

    if (isCyclic(newgraph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}

// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space complexity: O(V), where V is the number of vertices.

/*
the algorithm leverages the properties of DFS to detect back edges, which are the hallmarks of cycles in directed graphs.
*/