#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an interval
struct Interval {
    int start;
    int end;
};
// Comparison function to sort intervals by their end times
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}
// Function to find the maximum number of non-overlapping intervals
int intervalScheduling(vector<Interval>& intervals) {
    // Sort intervals by their end times
    sort(intervals.begin(), intervals.end(), compareIntervals);
    int count = 1; // Count of non-overlapping intervals
    int currentEnd = intervals[0].end;
    // Iterate through the sorted intervals
    for (int i = 1; i < intervals.size(); ++i) {
        // If the start time of the current interval is after the end time of the previous interval,
        // it can be included in the schedule
        if (intervals[i].start >= currentEnd) {
            ++count;
            currentEnd = intervals[i].end;
        }
    }

    return count;
}

int main() {
    // Example usage
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}, {8, 10}, {9, 11}};
    int maxNonOverlapping = intervalScheduling(intervals);
    cout << "Maximum number of non-overlapping intervals: " << maxNonOverlapping << endl;
    return 0;
}
