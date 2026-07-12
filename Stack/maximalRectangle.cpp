/* 
[
  ["1", "0", "1", "0", "0"],
  ["1", "0", "1", "1", "1"],
  ["1", "1", "1", "1", "1"],
  ["1", "0", "0", "1", "0"]
]

To find the largest rectangle of 1s, we look at the matrix row by row from top to bottom, building a 1D histogram array as we go. The "height" of each bar in our histogram is simply how many consecutive 1s are stacked directly on top of each other.
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
private:
    // This is your EXACT 1D histogram function from before
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > current_height) {
                int height = heights[st.top()];
                st.pop();
                int left_boundary = st.empty() ? -1 : st.top();
                max_area = max(max_area, height * (i - left_boundary - 1));
            }
            st.push(i);
        }
        return max_area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0); // 1D array to track cumulative column heights
        int global_max_area = 0;

        // Process the matrix row by row
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If it's '1', increase height. If it's '0', the vertical chain breaks!
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; 
                }
            }
            // Reuse your 1D logic for the current row's histogram
            global_max_area = max(global_max_area, largestRectangleArea(heights));
        }

        return global_max_area;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "The area of the largest rectangle is: " << result << endl;

    return 0;
}