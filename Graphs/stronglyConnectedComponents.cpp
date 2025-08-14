#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    
    // DFS for first pass (fills stack with vertices in order of finishing times)
    void DFSUtil(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited, st);
            }
        }
        
        st.push(v);
    }
    
    // DFS for second pass (on transposed graph)
    void DFSUtilTranspose(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtilTranspose(neighbor, visited, component);
            }
        }
    }
    
public:
    Graph(int V) : V(V), adj(V) {}
    
    // Add edge to graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    // Get transpose of the graph
    Graph getTranspose() {
        Graph g(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                g.addEdge(v, u);
            }
        }
        return g;
    }
    
    // Find and print all strongly connected components
    void printSCCs() {
        stack<int> st;
        vector<bool> visited(V, false);
        
        // First pass: fill stack with vertices in order of finishing times
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, st);
            }
        }
        
        // Get transpose of the graph
        Graph gt = getTranspose();
        
        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        
        // Second pass: process vertices in order defined by the stack
        int componentCount = 0;
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            
            if (!visited[v]) {
                componentCount++;
                vector<int> component;
                gt.DFSUtilTranspose(v, visited, component);
                
                // Print the strongly connected component
                cout << "Strongly Connected Component: ";
                for (int node : component) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }
        cout << "Total Strongly Connected Components: " << componentCount << endl;

    }
};

int main() {
    // Create a graph
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    
    cout << "Strongly Connected Components in the graph:\n";
    g.printSCCs();
    
    return 0;
}