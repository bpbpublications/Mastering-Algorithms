#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // Create temporary arrays for the left and right halves
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[low + i];

    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    long long count = 0;

    // Merge the two halves while counting inversions
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            count += leftSize - i;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return count;
}

long long inversionCount(vector<int>& arr, int low, int high) {
    long long count = 0;

    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively count inversions in the left half
        count += inversionCount(arr, low, mid);

        // Recursively count inversions in the right half
        count += inversionCount(arr, mid + 1, high);

        // Merge the two halves and count inversions
        count += mergeAndCount(arr, low, mid, high);
    }

    return count;
}

int main() {
    // Example usage
    vector<int> arr = {1, 20, 6, 4, 5};

    long long result = inversionCount(arr, 0, arr.size() - 1);

    cout << "Inversion Count: " << result << endl;

    return 0;
}
