#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Create empty buckets
    vector<float> buckets[n];

    // Step 2: Place array elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in the bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 4: Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

// Utility function to print an array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    float arr[] = {0.397, 0.535, 0.636, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
