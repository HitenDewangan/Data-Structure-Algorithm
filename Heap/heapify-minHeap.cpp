#include <iostream>
#include <vector>
#include <algorithm> // For std::swap
using namespace std;

// Function to perform heapify-down operation on a subtree rooted at 'idx'
// N is the size of the heap/array
void heapifyDownMin(vector<int>& arr, int N, int idx) {
    int smallest = idx;      // Initialize smallest as root
    int left = 2 * idx + 1;  // Left child
    int right = 2 * idx + 2; // Right child

    // If left child exists and is smaller than current smallest
    if (left < N && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child exists and is smaller than current smallest
    if (right < N && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != idx) {
        swap(arr[idx], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyDownMin(arr, N, smallest);
    }
}

// Function to build a min-heap from an unsorted array
// This is the O(N) heapify process
void buildMinHeap(vector<int>& arr) {
    int N = arr.size();

    // Start from the last non-leaf node and heapify downwards.
    // The last non-leaf node is at index (N/2) - 1.
    // This loop ensures that when heapifyDownMin is called for a node,
    // its children's subtrees are already min-heaps.
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapifyDownMin(arr, N, i);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {4, 10, 3, 5, 1, 12, 8, 9, 6};
    cout << "Original array 1: ";
    printArray(arr1);

    buildMinHeap(arr1);

    cout << "Heapified array 1 (Min-Heap): ";
    printArray(arr1); // Expected: Smallest element (1) at the beginning

    return 0;
}