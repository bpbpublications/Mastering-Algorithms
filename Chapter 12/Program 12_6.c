#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define structure for a graph
struct Graph {
    int V;
    int** adjMatrix;
};

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*) malloc(V * sizeof(int));
    }
    return graph;
}

// Utility function to print the adjacency matrix of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

// Function to construct and print MST for a graph represented using adjacency matrix
void primMST(struct Graph* graph) {
    int V = graph->V;
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    int mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            if (graph->adjMatrix[u][v] && mstSet[v] == 0 && graph->adjMatrix[u][v] < key[v])
                parent[v] = u, key[v] = graph->adjMatrix[u][v];
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph->adjMatrix[i][parent[i]]);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    graph->adjMatrix[0][1] = 2;
    graph->adjMatrix[0][2] = 3;
    graph->adjMatrix[0][3] = 1;
    graph->adjMatrix[0][4] = 4;
    graph->adjMatrix[1][2] = 1;
    graph->adjMatrix[1][3] = 5;
    graph->adjMatrix[1][4] = 3;
    graph->adjMatrix[2][3] = 2;
    graph->adjMatrix[2][4] = 1;
    graph->adjMatrix[3][4] = 6;

    // Since the graph is undirected, fill the other half of the matrix
    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) {
            graph->adjMatrix[j][i] = graph->adjMatrix[i][j];
        }
    }

    printf("Adjacency Matrix of the graph:\n");
    printGraph(graph);

    printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    primMST(graph);

    return 0;
}
