#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
int n;
vector<vector<int>> cost;
vector<bool> visited;
vector<int> path;
int minCost = INF;

struct Node {
    vector<int> path;
    int cost;
    int level;
    Node(vector<int> p, int c, int l) : path(p), cost(c), level(l) {}
};
int reducedMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();	int cost = 0;
    for (int i = 0; i < n; i++) {
        int minVal = *min_element(matrix[i].begin(), matrix[i].end());
        if (minVal != 0) {
            cost += minVal;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= minVal;
                }
            }
        }
    }
    vector<int> minVals(n, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] != INF && matrix[j][i] < minVals[i]) {
                minVals[i] = matrix[j][i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (minVals[i] != INF) {
            cost += minVals[i];
            for (int j = 0; j < n; j++) {
                if (matrix[j][i] != INF) {
                    matrix[j][i] -= minVals[i];
                }
            }
        }
    }
    return cost;
}
int bound(Node& node) {
    int n = node.path.size();
    vector<vector<int>> matrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = cost[node.path[i]][node.path[j]];
        }
    }
    int bound = node.cost + reducedMatrix(matrix);
    for (int i = 0; i < n; i++) {
        matrix[i][node.path.back()] = INF;
    }
    int temp = reducedMatrix(matrix);
    bound += temp;
    return bound;
}

void solve() {
    queue<Node> q;
    vector<int> path = {0};
    q.push(Node(path, 0, 0));
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if (node.level == n) {
            if (cost[node.path.back()][0] != INF) {
                int totalCost = node.cost + cost[node.path.back()][0];
                if (totalCost < minCost) {
                    minCost = totalCost;
                    path = node.path;
                }
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (find(node.path.begin(), node.path.end(), i) == node.path.end() && cost[node.path.back()][i] != INF) {
                    vector<int> newPath = node.path;
                    newPath.push_back(i);
                    int newCost = node.cost + cost[node.path.back()][i];
                    Node newNode(newPath, newCost, node.level + 1);
                    int boundVal = bound(newNode);
                    if (boundVal < minCost) {
                        q.push(newNode);
                    }
                }
            }
        }
    }
}
int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    cost = vector<vector<int>>(n, vector<int>(n, INF));
    visited = vector<bool>(n, false);
    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }     }
   solve();
    cout << "Minimum cost: " << minCost << endl;
    cout << "Optimal path: ";
    for (int city : path)
        cout << city + 1 << " ";
    	cout << endl; 	return 0;	}
