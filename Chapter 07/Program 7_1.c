#include <iostream>
#include <vector>
using namespace std;
int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main() {
    vector<int> values = {10, 15, 40};
    vector<int> weights = {1, 2, 3};
    int capacity = 6;
    cout << "Maximum value: " << knapsack(values, weights, capacity) << endl;
    return 0;
}
