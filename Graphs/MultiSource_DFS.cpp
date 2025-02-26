
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

void multisourceBFS(const vector<vector<int>>& graph, const vector<int>& sources, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX); // Initialize distances to infinity
    queue<int> q;

    // Add source nodes to the queue
    for (int source : sources) {
        dist[source] = 0;
        q.push(source);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == INT_MAX) { // If not visited from any source
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    // Example graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 4},
        {1},
        {2}
    };

    // Source nodes
    vector<int> sources = {0, 3};

    vector<int> distances;
    multisourceBFS(graph, sources, distances);

    cout << "Shortest distances from sources:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
