#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// A structure to represent a graph
struct Graph {
    int V, E;
    int** edges;
};

// A utility function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (int**)malloc(E * sizeof(int*));
    for (int i = 0; i < E; i++) {
        graph->edges[i] = (int*)malloc(2 * sizeof(int));
    }
    return graph;
}

// A utility function to find the subset of an element i
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// A function to contract an edge (u, v) in the given graph
void contractEdge(struct Graph* graph, int u, int v) {
    for (int i = 0; i < graph->E; i++) {
        if (graph->edges[i][0] == v)
            graph->edges[i][0] = u;
        if (graph->edges[i][1] == v)
            graph->edges[i][1] = u;
    }
}

// A function to copy a graph
struct Graph* copyGraph(struct Graph* graph) {
    struct Graph* newGraph = createGraph(graph->V, graph->E);
    for (int i = 0; i < graph->E; i++) {
        newGraph->edges[i][0] = graph->edges[i][0];
        newGraph->edges[i][1] = graph->edges[i][1];
    }
    return newGraph;
}

// A function to count the number of edges in the graph
int countEdges(struct Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->E; i++) {
        if (graph->edges[i][0] != graph->edges[i][1])
            count++;
    }
    return count;
}

// Karger's minimum cut algorithm
int KargerMinCut(struct Graph* graph) {
    int minCut = INT_MAX;

    for (int i = 0; i < graph->V * graph->V; i++) {
        struct Graph* copiedGraph = copyGraph(graph);
        int vertices = graph->V;

        while (vertices > 2) {
            int randomEdge = rand() % copiedGraph->E;
            int u = copiedGraph->edges[randomEdge][0];
            int v = copiedGraph->edges[randomEdge][1];

            contractEdge(copiedGraph, u, v);
            vertices--;
        }

        int cutEdges = countEdges(copiedGraph);
        if (cutEdges < minCut)
            minCut = cutEdges;

        free(copiedGraph);
    }

    return minCut;
}

// Driver program to test above functions
int main() {
    srand(time(NULL));

    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edges[0][0] = 0;
    graph->edges[0][1] = 1;

    // add edge 0-2
    graph->edges[1][0] = 0;
    graph->edges[1][1] = 2;

    // add edge 0-3
    graph->edges[2][0] = 0;
    graph->edges[2][1] = 3;

    // add edge 1-3
    graph->edges[3][0] = 1;
    graph->edges[3][1] = 3;

    // add edge 2-3
    graph->edges[4][0] = 2;
    graph->edges[4][1] = 3;

    printf("Minimum cut is %d\n", KargerMinCut(graph));

    return 0;
}
