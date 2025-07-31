#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Function to find the minimum computations required to merge sorted arrays
int optimalMergePattern(vector<int>& arr) {
    // Create a priority queue to store the sizes of the sorted arrays
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int totalComputations = 0;
    // Merge the sorted arrays until there's only one array left
    while (pq.size() > 1) {
        // Extract the two smallest arrays
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        // Merge the two arrays and update the total computations
        int mergedSize = first + second;
        totalComputations += mergedSize;
        // Add the merged array back to the priority queue
        pq.push(mergedSize);
    }

    return totalComputations;
}
int main() {
    // Example usage
    vector<int> arr = {4, 3, 2, 6};
    int minComputations = optimalMergePattern(arr);
    cout << "Minimum computations required: " << minComputations << endl;
    return 0;
}
