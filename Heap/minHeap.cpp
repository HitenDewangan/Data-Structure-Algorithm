#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap; // Vector to store heap elements eg. [3, 5, 9, 6, 8]

    void heapifyUp(int index) {
        if (index == 0) return;
        
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {  // recursive T.C O(log n) for 
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return min;
    }

    int getMin() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    size_t size() {
        return heap.size();
    }

    void print() {
        for (int num : heap) {
            cout << num << " ";
        }
        cout << endl;
    }
};


// =============== Example Usage ===============
int main() {
    MinHeap minHeap;

    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(9);
    minHeap.insert(6);
    minHeap.insert(8);

    cout << "Min Heap elements: ";
    minHeap.print();

    cout << "Minimum element: " << minHeap.getMin() << endl;

    cout << "Extracting minimum element: " << minHeap.extractMin() << endl;
    cout << "Min Heap after extraction: ";
    minHeap.print();

    return 0;
}