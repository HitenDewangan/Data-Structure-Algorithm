#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V));

    // Initialize distance matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Negative cycle detection (optional)
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative-weight cycle." << endl;
            return dist; // Return early
        }
    }
    return dist;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int V = matrix.size();
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    vector<vector<int>> shortestPaths = floydWarshall(graph);

    cout << "Shortest paths between all pairs of vertices:" << endl;
    printMatrix(shortestPaths);

    //Example of a negative cycle.
    vector<vector<int>> graph2 = {
        {0, 1, INT_MAX},
        {INT_MAX, 0, -2},
        {-1, INT_MAX, 0}
    };

    vector<vector<int>> shortestPaths2 = floydWarshall(graph2);

    return 0;
}