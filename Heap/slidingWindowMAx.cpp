#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements not in the window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result when window is formed
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

// =========== Example Usage ===========
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> maxInWindows = maxSlidingWindow(nums, k);
    
    cout << "Max in sliding windows: ";
    for (int num : maxInWindows) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}