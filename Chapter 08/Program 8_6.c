#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10;
bool isSafe(int v, bool graph[MAX][MAX], vector<int>& path, int pos, int V) {
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
bool hamCycleUtil(bool graph[MAX][MAX], vector<int>& path, int pos, int V) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, V))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
void hamiltonianCycle(bool graph[MAX][MAX], int V) {
    vector<int> path(V, -1);
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1, V)) {
        cout << "Hamiltonian cycle exists: ";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian cycle exists." << endl;
    }
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    bool graph[MAX][MAX];
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    hamiltonianCycle(graph, V);
    return 0;
}
