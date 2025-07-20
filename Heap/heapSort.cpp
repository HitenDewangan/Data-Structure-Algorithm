#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// --- Min-Heap Helper Functions ---

// Function to perform heapify-down operation on a subtree rooted at 'idx'
// N is the current size of the *active heap* part of the array
void heapifyDownMin(vector<int>& arr, int N, int idx) {
    int smallest = idx;      // Initialize smallest as root
    int left = 2 * idx + 1;  // Left child
    int right = 2 * idx + 2; // Right child

    // If left child exists within the active heap and is smaller than current smallest
    if (left < N && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child exists within the active heap and is smaller than current smallest
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

// Function to build a min-heap from an unsorted array (O(N) complexity)
void buildMinHeap(vector<int>& arr) {
    int N = arr.size();

    // Start from the last non-leaf node and heapify downwards.
    // The last non-leaf node is at index (N/2) - 1.
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapifyDownMin(arr, N, i);
    }
}

// --- Heap Sort Function (using Min-Heap) ---

void heapSortMinHeap(vector<int>& arr) {
    int N = arr.size();

    // Step 1: Build a min-heap from the input array
    // After this, arr[0] will contain the smallest element.
    buildMinHeap(arr);
    cout << "After building Min-Heap: ";
    for (int x : arr) { cout << x << " "; }
    cout << endl;

    // Step 2: Extract elements one by one from the heap
    // and place them at the end of the array.
    // This will result in a descending sorted array.
    for (int i = N - 1; i > 0; i--) {
        // Move current root (smallest element) to the end of the unsorted part
        swap(arr[0], arr[i]);

        // Call heapifyDownMin on the reduced heap.
        // The heap size effectively shrinks by 1 with each iteration.
        heapifyDownMin(arr, i, 0); // 'i' is the new effective heap size
    }
}

// Function to print the array
void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) {
        cout << label;
    }
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {4, 10, 3, 5, 1, 12, 8, 9, 6};
    printArray(arr1, "Original array 1: ");
    heapSortMinHeap(arr1);
    printArray(arr1, "Sorted array 1 (Descending): "); // Will be sorted in descending order

    // vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << "\n-----------------------------------\n";
    // printArray(arr2, "Original array 2: ");
    // heapSortMinHeap(arr2);
    // printArray(arr2, "Sorted array 2 (Descending): ");

    // vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // cout << "\n-----------------------------------\n";
    // printArray(arr3, "Original array 3: ");
    // heapSortMinHeap(arr3);
    // printArray(arr3, "Sorted array 3 (Descending): ");

    // vector<int> arr4 = {50, 20, 10, 5, 30, 40};
    // cout << "\n-----------------------------------\n";
    // printArray(arr4, "Original array 4: ");
    // heapSortMinHeap(arr4);
    // printArray(arr4, "Sorted array 4 (Descending): ");

    return 0;
}