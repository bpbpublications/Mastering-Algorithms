#include <iostream>
#include <vector>
// Function to perform Insertion Sort
void insertionSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    std::vector<int> elements = {64, 25, 12, 22, 11};

    std::cout << "Original Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    insertionSort(elements);
    std::cout << "Sorted Array: ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
