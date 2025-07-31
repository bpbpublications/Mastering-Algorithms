#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void topologicalSort(vector<vector<int>>& graph, int numVertices) {
    vector<int> inDegree(numVertices, 0);
    queue<int> zeroInDegreeQueue;
    vector<int> topoOrder;
    // Calculate in-degrees of all vertices
    for (int i = 0; i < numVertices; i++) {
        for (int j : graph[i]) {
            inDegree[j]++;
        }
    }
    // Enqueue vertices with zero in-degree
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            zeroInDegreeQueue.push(i);
        }
    }

    while (!zeroInDegreeQueue.empty()) {
        int vertex = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        topoOrder.push_back(vertex);
        // Decrease in-degree for all adjacent vertices
        for (int adjVertex : graph[vertex]) {
            inDegree[adjVertex]--;
            if (inDegree[adjVertex] == 0) {
                zeroInDegreeQueue.push(adjVertex);
            }
        }
    }

    // Check for a cycle
    if (topoOrder.size() != numVertices) {
        cout << "Graph has a cycle, topological sort not possible." << endl;
        return;
    }

    // Print topological order
    for (int vertex : topoOrder) {
        cout << vertex << " ";
    }
    cout << endl;
}
int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);
    // Example graph (DAG)
    graph[5] = { 2, 0 };
    graph[4] = { 0, 1 };
    graph[2] = { 3 };
    graph[3] = { 1 };
    topologicalSort(graph, numVertices);
    return 0;
}
