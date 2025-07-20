#include <iostream>
#include <queue>
using namespace std;

void stlHeapExamples() {
    // Max Heap (default)
    priority_queue<int> maxHeap;
    
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Insert elements
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    
    // Access top element
    cout << "MaxHeap top: " << maxHeap.top() << endl; // 4
    cout << "MinHeap top: " << minHeap.top() << endl; // 1
    
    // Remove top element
    maxHeap.pop();
    minHeap.pop();
}