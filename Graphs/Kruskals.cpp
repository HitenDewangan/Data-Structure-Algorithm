#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============= union find data structure ============
struct Edge {
    int src, dest, weight;
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
// ===================================================

// ============= Kruskal's Algorithm ==================================

vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    vector<Edge> result;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(numVertices);

    for (const auto& edge : edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) { // don't belong to the same component
            result.push_back(edge);
            uf.unite(edge.src, edge.dest);
        }
    }

    return result;
}

// =====================================================================


int main() {
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kruskalMST(edges, numVertices);

    cout << "Minimum Spanning Tree Edges:" << endl;
    int totalWeight = 0;
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}