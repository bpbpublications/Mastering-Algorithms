#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Define the number of cities
const int N = 4;

// Define a large number representing infinity
const int INF = INT_MAX;

// Function to implement the Travelling Salesman Problem using dynamic programming
int tsp(const vector<vector<int>>& dist) {
    int n = dist.size();
    int VISITED_ALL = (1 << n) - 1;

    // dp[mask][i] will store the minimum cost to visit all cities in mask and end at city i
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    // Initialize the base cases
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = dist[0][i];
    }

    // Iterate over all subsets of cities
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // If city i is in the subset represented by mask
                for (int j = 0; j < n; ++j) {
                    if ((mask & (1 << j)) && i != j) { // If city j is also in the subset and different from i
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[j][i]);
                    }
                }
            }
        }
    }

    // Calculate the final answer
    int answer = INF;
    for (int i = 1; i < n; ++i) { // Iterate over all cities except the starting city
        answer = min(answer, dp[VISITED_ALL][i] + dist[i][0]);
    }

    return answer;
}

int main() {
    // Define the distance matrix
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Call the tsp function and print the result
    cout << "The minimum cost of visiting all cities and returning to the start is: " << tsp(dist) << endl;

    return 0;
}
