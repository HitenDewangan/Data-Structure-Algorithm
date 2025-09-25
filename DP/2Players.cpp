#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Dynamic Programming approach with memoization
int solveMemo(const vector<int>& coins, int i, int j, vector<vector<int>>& memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    int take_i = coins[i] + min(
        (i + 2 <= j) ? solveMemo(coins, i + 2, j, memo) : 0,
        (i + 1 <= j - 1) ? solveMemo(coins, i + 1, j - 1, memo) : 0
    );
    
    int take_j = coins[j] + min(
        (i + 1 <= j - 1) ? solveMemo(coins, i + 1, j - 1, memo) : 0,
        (i <= j - 2) ? solveMemo(coins, i, j - 2, memo) : 0
    );
    
    return memo[i][j] = max(take_i, take_j);
}

// Function to find the winner
void findWinner(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) {
        cout << "No coins to play. It's a draw!" << endl;
        return;
    }
    
    // Calculate Player 1's max score using the DP solution
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int player1_score = solveMemo(coins, 0, n - 1, memo);
    
    // Calculate the total sum of all coins
    int total_sum = accumulate(coins.begin(), coins.end(), 0);
    
    // Calculate Player 2's score
    int player2_score = total_sum - player1_score;
    
    cout << "Player 1's max score: " << player1_score << endl;
    cout << "Player 2's max score: " << player2_score << endl;
    
    if (player1_score > player2_score) {
        cout << "Player 1 wins!" << endl;
    } else if (player2_score > player1_score) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    vector<int> coins1 = {8, 15, 3, 7}; // Example from previous response
    vector<int> coins2 = {2, 2, 2, 2};
    vector<int> coins3 = {5, 3, 7, 10, 1}; // Odd length array

    cout << "Game 1: {8, 15, 3, 7}" << endl;
    findWinner(coins1);
    cout << endl;
    
    cout << "Game 2: {2, 2, 2, 2}" << endl;
    findWinner(coins2);
    cout << endl;
    
    cout << "Game 3: {5, 3, 7, 10, 1}" << endl;
    findWinner(coins3);
    cout << endl;
    
    return 0;
}

// T.C. : O(n^2) due to memoization table
// S.C. : O(n^2) for the memoization table
// This code determines the winner of a two-player game where players alternately pick coins from either end of a line of coins.
