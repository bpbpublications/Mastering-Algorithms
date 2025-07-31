#include <stdio.h>
#include <conio.h>
// Function to perform binary search within a sorted array
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Return -1 if the target is not found
}

// Function to perform exponential search
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target)
        return 0; // If the target is found at index 0
    // Find the range where the target may lie
    int i = 1;
    while (i < size && arr[i] <= target)
        i *= 2;
    // Perform binary search within the identified range
    return binarySearch(arr, i / 2, (i < size) ? i : size - 1, target);
}

int main() {
    int arr[] = {2, 3, 5, 8, 10, 15, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int index = exponentialSearch(arr, size, target);
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found in the array\n", target);
    return 0;
}
