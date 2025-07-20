#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // stores lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores upper half
    
public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};

// =========== Example Usage ===========
int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.0
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5
    
    return 0;
}