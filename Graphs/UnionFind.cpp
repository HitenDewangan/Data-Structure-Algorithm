// path compression : means that when we are finding the parent of a node, we will make the parent of the node to be the root of the tree

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) {
            return false; // Same component, edge creates a cycle
        }
        // Union by rank
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

vector<pair<int, int>> buildAcyclicGraph(int n, int e, const vector<pair<int, int>>& edges) {
    UnionFind uf(n);
    vector<pair<int, int>> includedEdges;

    for (const auto& edge : edges) {
        if (uf.unite(edge.first, edge.second)) {
            includedEdges.push_back(edge);
        }
    }
    return includedEdges;
}

int main() {
    // int n, e;
    // cout << "Enter number of nodes (n) and edges (e): ";
    // cin >> n >> e;

    // vector<pair<int, int>> edges(e);
    // cout << "Enter edges (u v) one by one:" << endl;
    // for (int i = 0; i < e; ++i) {
    //     cin >> edges[i].first >> edges[i].second;
    // }

    // vector<pair<int, int>> acyclicEdges = buildAcyclicGraph(n, e, edges);

    // cout << "\nFinal edges in the acyclic graph:" << endl;
    // for (const auto& edge : acyclicEdges) {
    //     cout << edge.first << " " << edge.second << endl;
    // }
    

    //------- Example -------
    int n = 6;
    int e = 7;
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0}, // cycle
        {2, 4},
        {4, 5},
        {1, 5} //cycle
    };

    vector<pair<int, int>> acyclicEdges = buildAcyclicGraph(n, e, edges);

    cout << "\nFinal edges in the acyclic graph:" << endl;
    for (const auto& edge : acyclicEdges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}