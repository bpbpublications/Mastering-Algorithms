#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int source, destination, weight;
};
void BellmanFord(vector<Edge>& edges, int V, int E, int source) {
    vector<int> dist(V, numeric_limits<int>::max());
    vector<int> prev(V, -1);
    dist[source] = 0;
    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            cout << "Error: Negative Cycle Exists" << endl;
            return;
        }
    }
    // Print the shortest paths
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int source = 0;  // Source vertex
    BellmanFord(edges, V, E, source);
    return 0;
}
