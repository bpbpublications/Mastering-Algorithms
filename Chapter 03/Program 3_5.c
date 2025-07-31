#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    // Find the maximum and minimum elements in the array
    int max_element = *std::max_element(arr.begin(), arr.end());
    int min_element = *std::min_element(arr.begin(), arr.end());

    int range = max_element - min_element + 1;

    // Create a count array to store the count of each element
    std::vector<int> count(range, 0);

    // Count occurrences of each element
    for (int i = 0; i < n; ++i) {
        count[arr[i] - min_element]++;
    }

    // Modify count array to store cumulative sum
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // Create the sorted array using count array
    std::vector<int> sorted(n);
    for (int i = n - 1; i >= 0; --i) {
        sorted[count[arr[i] - min_element] - 1] = arr[i];
        count[arr[i] - min_element]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = sorted[i];
    }
}

int main() {
    std::vector<int> elements = {64, 25, 12, 22, 11};

    std::cout << "Original Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    countingSort(elements);

    std::cout << "Sorted Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
