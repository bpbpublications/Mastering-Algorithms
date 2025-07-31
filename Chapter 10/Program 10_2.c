#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS1(int v, vector<bool>& visited, stack<int>& finishStack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS1(u, visited, finishStack);
            }
        }
        finishStack.push(v);
    }

    void DFS2(int v, vector<bool>& visited, vector<int>& SCC) {
        visited[v] = true;
        SCC.push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS2(u, visited, SCC);
            }
        }
    }

    Graph transpose() {
        Graph transposed(V);
        for (int v = 0; v < V; ++v) {
            for (int u : adj[v]) {
                transposed.addEdge(u, v);
            }
        }
        return transposed;
    }

    vector<vector<int>> findSCCs() {
        vector<bool> visited(V, false);
        stack<int> finishStack;
        // Step 1: Fill finishStack in order of finish times
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                DFS1(v, visited, finishStack);
            }
        }

        // Step 2: Get the transposed graph
        Graph transposed = transpose();
        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        // Step 3: Process vertices in order defined by finishStack
        vector<vector<int>> SCCs;
        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();
            if (!visited[v]) {
                vector<int> SCC;
                transposed.DFS2(v, visited, SCC);
                SCCs.push_back(SCC);
            }
        }
        return SCCs;
    }
};

int main() {
    Graph g(5); // Example graph with 5 vertices

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    // Finding Strongly Connected Components
    vector<vector<int>> SCCs = g.findSCCs();
    // Output SCCs
    cout << "Strongly Connected Components:\n";
    for (const auto& SCC : SCCs) {
        for (int v : SCC) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
