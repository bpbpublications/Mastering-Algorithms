#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Structure to represent a job
struct Job {
    char id;    // Job ID
    int deadline; // Deadline of job
    int profit; // Profit associated with the job
};
// Function to compare jobs based on their profit
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}
// Function to find the maximum profit by scheduling jobs
void findMaxProfit(Job arr[], int n) {
    // Sort jobs based on profit in decreasing order
    sort(arr, arr + n, compare);
    vector<int> result(n, -1); // To store result (Sequence of jobs)
    vector<bool> slot(n, false); // To keep track of free time slots
    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }
    // Print the sequence of jobs
    cout << "The sequence of jobs with maximum profit is: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout << arr[result[i]].id << " ";
    }
    cout << endl;
}
int main() {
    // Example jobs
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);
   // Find the maximum profit
    findMaxProfit(arr, n);
    return 0;
}
