#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {  // T.C. : O(E*log(V))
    
    int V = adj.size();
    vector<int> dist(V, 1e9); 
    dist[src] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) { 
            int edgeWeight = it.second; 
            int adjNode = it.first; 

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}


int main() {
    // sample input
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {4, 3}},
        {{0, 1}, {4, 2}, {5, 4}},
        {{0, 6}, {5, 1}},
        {{1, 3}, {2, 2}, {6, 5}},
        {{2, 4}, {3, 1}},
        {{4, 5}}
    };

    int src = 0;

    vector<int> dist = dijkstra(adj, src);

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    
}