#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source;
    int dest;
    int weight;
};

bool bellmanFord(int vertices, const vector<Edge>& edges, int source, vector<int>& distances) {
    // Initialize distances
    distances.resize(vertices, INT_MAX);
    distances[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edges) {
            if (distances[edge.source] != INT_MAX && 
                distances[edge.source] + edge.weight < distances[edge.dest]) {
                distances[edge.dest] = distances[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        if (distances[edge.source] != INT_MAX && 
            distances[edge.source] + edge.weight < distances[edge.dest]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int V = 5;  // Number of vertices
    const int source = 0;

    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7},
        {1, 2, 8}, {1, 3, 5}, {1, 4, -4},
        {2, 3, -3}, {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2}, {4, 3, 7}
    };

    vector<int> distances;
    bool success = bellmanFord(V, edges, source, distances);

    if (success) {
        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t" << distances[i] << "\n";
        }
    } else {
        cout << "Graph contains negative weight cycle reachable from source!\n";
    }

    return 0;
}