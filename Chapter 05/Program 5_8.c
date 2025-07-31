#include <iostream>
#include <limits>

using namespace std;

int maxCrossingSubarraySum(int arr[], int low, int mid, int high) {
    int leftSum = numeric_limits<int>::min();
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = numeric_limits<int>::min();
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftMax = maxSubarraySum(arr, low, mid);
    int rightMax = maxSubarraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSubarraySum(arr, low, mid, high);

    return max({leftMax, rightMax, crossMax});
}

int main() {
    // Example usage
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
