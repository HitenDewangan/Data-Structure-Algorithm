#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency; 
    for (int num : nums) {
        frequency[num]++;
    }
    
    priority_queue<pair<int, int>, 
                      vector<pair<int, int>>, 
                      greater<pair<int, int>>> minHeap; // priority will be based on frequency, ie second element of pair
    
    for (auto& [num, count] : frequency) {
        minHeap.push({count, num});    // notice here we push a pair of (frequency, number)
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}

// =========== Example Usage ===========
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> topK = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}