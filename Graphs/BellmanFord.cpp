#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int V, const vector<Edge>& edges, int src, vector<int>& dist) {
    dist.assign(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {

                // check for negative-weight cycles
                if(i == V - 1) {
                    return false;
                }

                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }
    return true; // No negative cycle
}

int main() {
    int V = 5; // Number of vertices
    int src = 0; // Source vertex

    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7},
        {1, 2, 8}, {1, 3, 5}, {1, 4, -4},
        {2, 3, -3}, {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2}, {4, 3, 7}
    };

    vector<int> dist;
    bool hasNoNegativeCycle = bellmanFord(V, edges, src, dist);

    if (hasNoNegativeCycle) {
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < V; ++i)
            cout << i << "\t" << dist[i] << endl;
    } else {
        cout << "Graph contains a negative-weight cycle." << endl;
    }

    //  ============ negative cycle example ============
    // vector<Edge> edges2 = {
    //     {0, 1, 1}, {1, 2, -1}, {2, 0, -1}
    // };

    // vector<int> dist2;
    // bool hasNoNegativeCycle2 = bellmanFord(3, edges2, 0, dist2);

    // if (hasNoNegativeCycle2) {
    //     cout << "Vertex\tDistance from Source" << endl;
    //     for (int i = 0; i < 3; ++i)
    //         cout << i << "\t" << dist2[i] << endl;
    // } else {
    //     cout << "Graph contains a negative-weight cycle." << endl;
    // }

    return 0;
}