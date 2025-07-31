#include <iostream>
#include <vector>

// Function to perform Selection Sort
void selectionSort(std::vector<int> &arr) {
    int n = arr.size();

    // Iterate through the array
    for (int i = 0; i < n - 1; ++i) {
        // Assume the current index has the minimum value
        int min_index = i;

        // Find the index of the minimum element in the unsorted segment
        for (int j = i + 1; j < n; ++j) {
            // Compare current element with the assumed minimum
            if (arr[j] < arr[min_index]) {
                // If a smaller element is found, update the minimum index
                min_index = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        std::swap(arr[min_index], arr[i]);
    }
}

int main() {
    // Example vector of integers
    std::vector<int> elements = {64, 25, 12, 22, 11};

    // Display the original array
    std::cout << "Original Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Sort the array using Selection Sort
    selectionSort(elements);

    // Display the sorted array
    std::cout << "Sorted Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
