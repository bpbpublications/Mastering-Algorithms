#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& set, int target_sum) {
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target_sum + 1, false));

    // Base case: an empty subset can sum up to 0
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target_sum; ++j) {
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j]; // Exclude current element
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]; // Include or exclude current element
            }
        }
    }
    return dp[n][target_sum];
}
int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int target_sum = 9;
    if (subsetSum(set, target_sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }
    return 0;
}
