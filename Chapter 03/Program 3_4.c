#include <iostream>
#include <vector>
// Function to perform Shell Sort
void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    // Generate gap sequence (Knuth sequence)
    int gap = 1;
    while (gap <= n / 3) {
        gap = gap * 3 + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            // Perform Insertion Sort on subarrays
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 3; // Reduce the gap
    }
}

int main() {
    std::vector<int> elements = {64, 25, 12, 22, 11};

    std::cout << "Original Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    shellSort(elements);
    std::cout << "Sorted Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}

