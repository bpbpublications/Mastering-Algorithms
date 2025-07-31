#include <iostream>
#include <vector>

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(const std::vector<int>& arr, int low, int high) {
    MinMax result;

    // Base case: If the sequence has only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // If the sequence has more than one element, divide and conquer
    int mid = (low + high) / 2;
    MinMax leftResult = findMinMax(arr, low, mid);
    MinMax rightResult = findMinMax(arr, mid + 1, high);

    // Combine the results
    result.min = std::min(leftResult.min, rightResult.min);
    result.max = std::max(leftResult.max, rightResult.max);

    return result;
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = arr.size();

    MinMax result = findMinMax(arr, 0, n - 1);

    std::cout << "Minimum element: " << result.min << std::endl;
    std::cout << "Maximum element: " << result.max << std::endl;

    return 0;
}
