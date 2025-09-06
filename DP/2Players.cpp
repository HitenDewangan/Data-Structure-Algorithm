#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Memoization (Top-down) approach
int solveMemo(const vector<int>& coins, int i, int j, vector<vector<int>>& memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    // Player 1's turn
    // Choice 1: Pick the coin at index i
    // Opponent will then face coins from i+1 to j. The opponent will play optimally,
    // and Player 1 will get the minimum possible score from the opponent's moves.
    int take_i = coins[i] + min(
        (i + 2 <= j) ? solveMemo(coins, i + 2, j, memo) : 0,
        (i + 1 <= j - 1) ? solveMemo(coins, i + 1, j - 1, memo) : 0
    );
    
    // Choice 2: Pick the coin at index j
    // Opponent will then face coins from i to j-1.
    int take_j = coins[j] + min(
        (i + 1 <= j - 1) ? solveMemo(coins, i + 1, j - 1, memo) : 0,
        (i <= j - 2) ? solveMemo(coins, i, j - 2, memo) : 0
    );
    
    return memo[i][j] = max(take_i, take_j);
}

int optimalStrategyMemoization(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return solveMemo(coins, 0, n - 1, memo);
}

// Tabulation (Bottom-up) approach
int optimalStrategyTabulation(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) {
        return 0;
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Fill the table diagonally, for increasing subproblem sizes (gaps)
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            
            // a: score if opponent picks coins[i+1] and we get from [i+2...j]
            int a = (i + 2 <= j) ? dp[i + 2][j] : 0;
            // b: score if opponent picks coins[j-1] and we get from [i+1...j-1]
            int b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            // c: score if opponent picks coins[j-1] and we get from [i...j-2]
            int c = (i <= j - 2) ? dp[i][j - 2] : 0;
            
            // Player 1 takes coins[i], so opponent faces subproblem [i+1...j]
            int take_i = coins[i] + min(a, b);
            
            // Player 1 takes coins[j], so opponent faces subproblem [i...j-1]
            int take_j = coins[j] + min(b, c);
            
            // Take the maximum of the two choices
            dp[i][j] = max(take_i, take_j);
        }
    }
    
    return dp[0][n - 1];
}

// Greedy approach for even number of coins
// This approach works by picking all coins from either the odd-indexed or even-indexed positions,
// whichever sum is greater.
int optimalStrategyGreedyEven(const vector<int>& coins) {
    int n = coins.size();
    if (n % 2 != 0) {
        return -1; // Not applicable for an odd number of coins
    }

    long long even_sum = 0;
    long long odd_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            odd_sum += coins[i];
        } else {
            even_sum += coins[i];
        }
    }

    return max(even_sum, odd_sum);
}

int main() {
    vector<int> coins1 = {8, 15, 3, 7}; // Even length
    vector<int> coins2 = {2, 2, 2, 2}; // Even length
    vector<int> coins3 = {20, 30, 2, 2, 2, 10}; // Even length
    vector<int> coins4 = {5, 3, 7, 10, 1}; // Odd length

    // Dynamic Programming (Memoization)
    cout << "Memoization Approach:" << endl;
    cout << "Max score for {8, 15, 3, 7}: " << optimalStrategyMemoization(coins1) << endl;
    cout << "Max score for {2, 2, 2, 2}: " << optimalStrategyMemoization(coins2) << endl;
    cout << "Max score for {5, 3, 7, 10, 1}: " << optimalStrategyMemoization(coins4) << endl;
    
    cout << "\nTabulation Approach:" << endl;
    cout << "Max score for {8, 15, 3, 7}: " << optimalStrategyTabulation(coins1) << endl;
    cout << "Max score for {2, 2, 2, 2}: " << optimalStrategyTabulation(coins2) << endl;
    cout << "Max score for {5, 3, 7, 10, 1}: " << optimalStrategyTabulation(coins4) << endl;

    // Greedy Approach (only for even-length arrays)
    cout << "\nGreedy Approach (for even length arrays):" << endl;
    cout << "Max score for {8, 15, 3, 7}: " << optimalStrategyGreedyEven(coins1) << endl;
    cout << "Max score for {2, 2, 2, 2}: " << optimalStrategyGreedyEven(coins2) << endl;
    
    return 0;
}
