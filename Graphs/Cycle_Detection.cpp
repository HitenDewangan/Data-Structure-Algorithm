#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Undirected Graphs

// 1. DFS with Parent Tracking
bool dfsUndirected(int node, int parent, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfsUndirected(neighbor, node, visited, graph)) return true;
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

bool isCyclicUndirectedDFS(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            if (dfsUndirected(node, -1, visited, graph)) return true;
        }
    }
    return false;
}

// 2. Union-Find (Disjoint Set)
struct UnionFind {
    vector<int> parent;
    UnionFind(int size) : parent(size) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false; // Cycle detected
        parent[fy] = fx;
        return true;
    }
};

bool isCyclicUnionFind(const vector<pair<int, int>>& edges, int numNodes) {
    UnionFind uf(numNodes);
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        if (!uf.unite(u, v)) return true;
    }
    return false;
}

// Directed Graphs

// 1. DFS with Recursion Stack
bool dfsDirected(int node, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& graph) {
    visited[node] = true;
    recStack[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, visited, recStack, graph)) return true;
        } else if (recStack[neighbor]) {
            return true; // Cycle detected
        }
    }
    recStack[node] = false;
    return false;
}

bool isCyclicDirectedDFS(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false), recStack(n, false);
    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            if (dfsDirected(node, visited, recStack, graph)) return true;
        }
    }
    return false;
}

// 2. Kahn's Algorithm (Topological Sort)
bool isCyclicKahn(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) inDegree[v]++;
    }
    
    queue<int> q;
    for (int u = 0; u < n; ++u) {
        if (inDegree[u] == 0) q.push(u);
    }
    
    int processed = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processed++;
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    return processed != n; // Cycle exists if processed ≠ total nodes
}

int main() {
    // Undirected Graph Tests
    vector<vector<int>> undirectedGraph1 = {{1}, {0, 2}, {1, 3}, {2}};
    cout << "Undirected Graph DFS 1: " << (isCyclicUndirectedDFS(undirectedGraph1) ? "Cycle" : "No Cycle") << endl;

    vector<vector<int>> undirectedGraph2 = {{1,2},{0,2},{0,1}};
    cout << "Undirected Graph DFS 2: " << (isCyclicUndirectedDFS(undirectedGraph2) ? "Cycle" : "No Cycle") << endl;

    vector<pair<int, int>> undirectedEdges = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Undirected Graph Union-Find: " << (isCyclicUnionFind(undirectedEdges, 3) ? "Cycle" : "No Cycle") << endl;

    // Directed Graph Tests
    vector<vector<int>> directedGraph1 = {{1}, {2}, {3}, {1}};
    cout << "Directed Graph DFS 1: " << (isCyclicDirectedDFS(directedGraph1) ? "Cycle" : "No Cycle") << endl;

    vector<vector<int>> directedGraph2 = {{1, 2}, {2, 3}, {3}};
    cout << "Directed Graph DFS 2: " << (isCyclicDirectedDFS(directedGraph2) ? "Cycle" : "No Cycle") << endl;

    vector<vector<int>> directedGraph3 = {{1, 2}, {2, 3}, {3}};
    cout << "Directed Graph Kahn 1: " << (isCyclicKahn(directedGraph3) ? "Cycle" : "No Cycle") << endl;

    vector<vector<int>> directedGraph4 = {{1},{2},{3},{}};
    cout << "Directed Graph Kahn 2: " << (isCyclicKahn(directedGraph4) ? "Cycle" : "No Cycle") << endl;
    return 0;
}