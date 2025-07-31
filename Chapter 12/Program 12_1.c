#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Randomized Partition function
int randomizedPartition(int arr[], int low, int high) {
    int pivot_index = low + rand() % (high - low + 1);
    swap(&arr[pivot_index], &arr[high]);
    return partition(arr, low, high);
}

// Randomized QuickSort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot_index - 1);
        randomizedQuickSort(arr, pivot_index + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the Randomized QuickSort
int main() {
    srand(time(0)); // Seed for random number generation
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    randomizedQuickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
