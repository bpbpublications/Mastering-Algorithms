#include <iostream>
    #include <vector>

    void countingSort(std::vector<int>& arr, int exp) {
        int n = arr.size();
        std::vector<int> output(n);
        std::vector<int> count(10, 0);

        for (int i = 0; i < n; ++i)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; ++i)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; ++i)
            arr[i] = output[i];
    }

    void radixSort(std::vector<int>& arr) {
        int max_element = *std::max_element(arr.begin(), arr.end());

        for (int exp = 1; max_element / exp > 0; exp *= 10)
            countingSort(arr, exp);
    }

    int main() {
        std::vector<int> elements = {170, 45, 75, 90, 802, 24, 2, 66};

        std::cout << "Original Array: ";
        for (int elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        radixSort(elements);

        std::cout << "Sorted Array: ";
        for (int elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        return 0;
    }
