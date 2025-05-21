#include <vector>
using namespace std;

class SubmatrixSum {
private:
    vector<vector<int>> prefix;

public:
    SubmatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));
        // Initialize prefix sum array
        prefix[0][0] = matrix[0][0];
        for (int i = 1; i < n; ++i) { // Fill first column
            prefix[i][0] = matrix[i][0] + prefix[i - 1][0];
        }
        for (int j = 1; j < m; ++j) { // Fill first row
            prefix[0][j] = matrix[0][j] + prefix[0][j - 1];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    // Function to get the sum of submatrix defined by (row1, col1) to (row2, col2)
    int query(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) return 0; // Invalid query
        int total = prefix[row2][col2];
        if (row1 > 0) total -= prefix[row1 - 1][col2];
        if (col1 > 0) total -= prefix[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) total += prefix[row1 - 1][col1 - 1];
        return total;
    }
};

// Example usage:
#include <iostream>
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    SubmatrixSum solver(matrix);
    vector<vector<int>> qMat = {
        {0, 0, 1, 1},  // Sum of top-left 2x2 (1+2+4+5=12)
        {1, 1, 2, 2},  // Sum of bottom-right 2x2 (5+6+8+9=28)
        {0, 0, 2, 2}   // Sum of entire matrix (45)
    };
    for (auto& q : qMat) {
        cout << solver.query(q[0], q[1], q[2], q[3]) << endl;
    }
    // Outputs: 12, 28, 45
    return 0;
}