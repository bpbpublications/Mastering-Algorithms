#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the Levenshtein Distance between two strings
int levenshteinDistance(const string& str1, const string& str2) {
    int m = str1.size();
    int n = str2.size();
    // Create a 2D vector to store the distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    // Initialize the base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i; // Distance from str1[0..i-1] to an empty str2
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j; // Distance from an empty str1 to str2[0..j-1]
    }
    // Fill the rest of the dp matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No change needed
            } else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // Deletion
                    dp[i][j - 1] + 1,    // Insertion
                    dp[i - 1][j - 1] + 1 // Substitution
                });
            }
        }
    }

    // The bottom-right cell contains the Levenshtein Distance
    return dp[m][n];
}
int main() {
    string str1 = "kitten";
    string str2 = "sitting";
    int distance = levenshteinDistance(str1, str2);
    cout << "The Levenshtein Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << distance << endl;
    return 0;
}
