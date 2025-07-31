#include <bits/stdc++.h>
using namespace std;
struct Item {
    int profit, weight;
    Item(int p, int w) {
        profit = p;
        weight = w;
    }
};
static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int N) {
    sort(arr, arr + N, cmp);
    // Rest of the implementation...
    // Return the maximum profit achieved.
}
// Example usage:
int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int knapsackCapacity = 50;
    double result = fractionalKnapsack(knapsackCapacity, items, 3);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
