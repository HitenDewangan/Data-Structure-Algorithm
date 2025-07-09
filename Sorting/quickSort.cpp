#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Lomuto partition: Last element as pivot
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot = last element
    int i = low - 1; // Index for elements <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Place pivot in correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot index
}

// Recursive QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_idx = partition(arr, low, high);
        quickSort(arr, low, pivot_idx - 1); // Left of pivot
        quickSort(arr, pivot_idx + 1, high); // Right of pivot
    }
}

// Wrapper for easier use
void quickSort(std::vector<int>& arr) {
    if (!arr.empty()) {
        quickSort(arr, 0, arr.size() - 1);
    }
}

// Test
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Original: ";
    for (int x : arr) std::cout << x << " ";
    
    quickSort(arr);
    
    std::cout << "\nSorted:   ";
    for (int x : arr) std::cout << x << " ";
    
    return 0;
}