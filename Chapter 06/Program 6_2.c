#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};
// Structure to represent a graph
class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    // Add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }
    // Find operation for disjoint set
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }
    // Union operation for disjoint set
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }
    // Kruskal's algorithm to find MST
    void KruskalMST() {
        vector<Edge> result; // This will store the MST
        int i = 0; // Index used to pick next edge
        // Step 1: Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });
        // Allocate memory for creating V subsets
        vector<int> parent(V, -1);
        // Number of edges to be taken is equal to V-1
        while (result.size() < V - 1 && i < E) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);
            // If including this edge does not cause cycle, include it
            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
            }
        }
        // Print the contents of result[] to display the built MST
        cout << "Edges in MST:\n";
        for (i = 0; i < result.size(); ++i)
            cout << result[i].src << " - " << result[i].dest << "  Weight: " << result[i].weight << endl;
    }
};
int main() {
    // Example usage
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph(V, E);
    // Adding edges to the graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    // Finding minimum spanning tree
    graph.KruskalMST();
    return 0;
}
