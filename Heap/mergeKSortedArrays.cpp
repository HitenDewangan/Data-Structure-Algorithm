#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Element {
    int value;
    int arrayIndex;
    int elementIndex;
    
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {  // T.C: O(N log K), S.C: O(K)
    if (arrays.empty()) return {};
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    
    // Push first element of each array
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);
        
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], 
                        current.arrayIndex, 
                        current.elementIndex + 1});
        }
    }
    
    return result;
}

// =========== Example Usage ===========
int main() {
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {0, 10, 11, 12, 13}
    };
    
    vector<int> mergedArray = mergeKSortedArrays(arrays);
    
    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}