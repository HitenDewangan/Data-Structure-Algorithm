#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

// Partition function using Hoare's scheme
int partition(vector<int>& arr, int low, int high) {
    // Choose middle element as pivot to avoid worst-case behavior
    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Find leftmost element >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers meet, partition is complete
        if (i >= j) return j;

        // Swap mismatched elements
        swap(arr[i], arr[j]);
    }
}

// Recursive QuickSort helper
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the split point
        int split = partition(arr, low, high);

        // Recursively sort left and right partitions
        quickSortHelper(arr, low, split);
        quickSortHelper(arr, split + 1, high);
    }
}

// Main QuickSort function (user-friendly interface)
void quickSort(vector<int>& arr) {
    if (arr.empty()) return;
    quickSortHelper(arr, 0, arr.size() - 1);
}


int main() {
    vector<int> arr = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    quickSort(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    // Output: -6 -3 1 2 3 5 6 8 9
    return 0;
}