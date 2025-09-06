#include <vector>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void buildTree(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * node + 1, start, mid);
        buildTree(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Change operation as needed
    }
    
    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(2 * node + 1, start, mid, idx, val);
        } else {
            updateTree(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Change operation as needed
    }
    
    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0; // Change based on operation
        if (l <= start && end <= r) return tree[node]; // Current segment is completely within range
        
        int mid = start + (end - start) / 2;
        int left = queryTree(2 * node + 1, start, mid, l, r);
        int right = queryTree(2 * node + 2, mid + 1, end, l, r);
        return left + right; // Change operation as needed
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        int height = (int)ceil(log2(n)); 
        int size = 2 * (int)pow(2, height) - 1; // formula is : 2^(height+1) - 1
        tree.resize(size);
        buildTree(nums, 0, 0, n - 1);
    }
    
    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        return queryTree(0, 0, n - 1, l, r);
    }
};


// Example usage
int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(nums);
    
    cout << "Sum of values in range [1, 3]: " << segTree.query(1, 3) << endl; // Output: 15
    segTree.update(1, 10); // Update index 1 to value 10
    cout << "Sum of values in range [1, 3] after update: " << segTree.query(1, 3) << endl; // Output: 22
    
    return 0;
}