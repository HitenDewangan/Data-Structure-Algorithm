#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return max;
    }

    int getMax() {
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
    MaxHeap maxHeap;

    maxHeap.insert(3);
    maxHeap.insert(5);
    maxHeap.insert(9);
    maxHeap.insert(6);
    maxHeap.insert(8);

    cout << "Max Heap elements: ";
    maxHeap.print();

    cout << "Maximum element: " << maxHeap.getMax() << endl;

    cout << "Extracting maximum element: " << maxHeap.extractMax() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.print();

    // insert more elements
    maxHeap.insert(2);
    cout << "Max Heap after inserting 10: ";
    maxHeap.print();

    return 0;
}