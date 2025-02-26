#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPathBFS(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == end) {
            break; // Destination found
        }
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruct the path
    vector<int> path;
    if (!visited[end]) {
        return path; // Empty path if end is unreachable
    }
    
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // int n, m;
    // cout << "Enter number of nodes and edges: ";
    // cin >> n >> m;
    
    // vector<vector<int>> graph(n);
    // cout << "Enter edges (u v):" << endl;
    // for (int i = 0; i < m; ++i) {
    //     int u, v;
    //     cin >> u >> v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u); // Omit this line for directed graphs
    // }

    vector<vector<int>> graph = {
        {3, 2},         // Node 1: 
        {1, 6, 4},      // Node 2: 
        {9, 1, 6},     // Node 3: 
        {2, 11, 6},     // Node 4
        {7, 8, 11},       // Node 5: 
        {3, 4, 8, 2},       // Node 6: 
        {8, 9, 10, 5},     // Node 7: 
        {11,5, 7, 6},     // Node 8:
        {3, 10, 7},     // Node 9:
        {7, 9},         // Node 10:
        {4, 5, 8}      // Node 11:
    };
    
    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;
    
    vector<int> path = shortestPathBFS(graph, start, end);
    
    if (path.empty()) {
        cout << "No path exists from " << start << " to " << end << endl;
    } else {
        cout << "Shortest path length: " << path.size() - 1 << endl;
        cout << "Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}