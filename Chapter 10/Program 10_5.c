#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Number of vertices in the graph
#define V 4


// A function to print the solution matrix
void printSolution(const vector<vector<int>>& dist) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF" << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}


// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    // Initialize the solution matrix same as input graph matrix
    vector<vector<int>> dist = graph;


    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // Print the shortest distance matrix
    printSolution(dist);
}


int main() {
    vector<vector<int>> graph = { {0, 5, INT_MAX, 10},
                                 		         {INT_MAX, 0, 3, INT_MAX},
                                  		         {INT_MAX, INT_MAX, 0, 1},
                                  		        {INT_MAX, INT_MAX, INT_MAX, 0} };
    // Function call
    floydWarshall(graph);
    return 0;
}
