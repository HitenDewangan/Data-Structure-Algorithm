#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat, missing;
        int n = nums.size();
        vector<int> present(n+1);
        for(int i=0; i<n; i++){
            present[nums[i]]++;
            if(present[nums[i]] > 1){
                repeat = nums[i];
                missing = nums[i] + 1;
                return {repeat, missing};
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = sol.findErrorNums(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}