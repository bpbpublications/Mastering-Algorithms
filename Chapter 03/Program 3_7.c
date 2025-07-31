  #include <iostream>
    #include <vector>
    #include <algorithm>

    // Function to perform Bucket Sort
    void bucketSort(std::vector<float>& arr) {
        int n = arr.size();

        // Create n empty buckets
        std::vector<std::vector<float>> buckets(n);

        // Distribution of elements into buckets
        for (int i = 0; i < n; ++i) {
            int index = n * arr[i];
            buckets[index].push_back(arr[i]);
        }

        // Sorting individual buckets (using a suitable sorting algorithm)
        for (int i = 0; i < n; ++i) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }

        // Concatenate sorted buckets to get the final sorted array
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (float num : buckets[i]) {
                arr[index++] = num;
            }
        }
    }

    int main() {
        std::vector<float> elements = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

        std::cout << "Original Array: ";
        for (float elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        bucketSort(elements);

        std::cout << "Sorted Array: ";
        for (float elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        return 0;
    }
