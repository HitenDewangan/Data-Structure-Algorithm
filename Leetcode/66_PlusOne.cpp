#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If we are here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main() {
    Solution sol;
    vector<int> digits = {8, 9, 9, 9};
    vector<int> result = sol.plusOne(digits);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}