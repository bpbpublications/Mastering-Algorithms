#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
struct Node {
    vector<bool> job_schedule;
    int level;
    int profit;
    int bound;
};
// Comparison function to sort jobs according to their profits
bool jobComparator(Job a, Job b) {
    return (a.profit > b.profit);	}
// Function to calculate upper bound of profit in subtree rooted with 'u'
int calculateBound(Node u, int n, vector<Job>& jobs) {
    if (u.level >= n) return 0;
    int profit_bound = u.profit;
    int total_time = 0;
    for (int i = u.level; i < n; i++) {
        total_time += jobs[i].deadline;
        if (total_time <= jobs[i].deadline) {
            profit_bound += jobs[i].profit;
        }
    }  return profit_bound;
}
// Branch and Bound algorithm for Job Sequencing
void jobSequencing(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), jobComparator);
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.job_schedule.resize(n, false);
    u.bound = calculateBound(u, n, jobs);
    Q.push(u);
    int max_profit = 0;
    vector<bool> best_schedule;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u.level == -1) v.level = 0;
        if (u.level == n - 1) continue;
        v.level = u.level + 1;
        v.job_schedule = u.job_schedule;
        v.job_schedule[v.level] = true;
        v.profit = u.profit + jobs[v.level].profit;
        if (v.profit > max_profit) {
            max_profit = v.profit;
            best_schedule = v.job_schedule;
        }
        v.bound = calculateBound(v, n, jobs);
        if (v.bound > max_profit) Q.push(v);
        v.job_schedule[v.level] = false;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, jobs);
        if (v.bound > max_profit) Q.push(v);
    }
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (best_schedule[i]) {
            cout << jobs[i].id << " ";
        }
    }
    cout << "\n Max Profit: " << max_profit << endl;
}
int main() {
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    int n = jobs.size();
    jobSequencing(jobs, n);
    return 0;
}
