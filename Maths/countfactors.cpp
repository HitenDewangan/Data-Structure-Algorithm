// Given N, for all numbers from 1 to N, find the number of factors of each number.
// T.C: O(N log N), S.C: O(N)
// This algorithm counts the number of factors for each number from 1 to N by iterating through each number and its multiples.

// Code
#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of factors for each number from 1 to N
void countFactors(int N) {
    vector<int> factors(N + 1, 0); // Initialize a vector to store the count of factors for each number

    // Count factors for each number from 1 to N
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            factors[j]++; // Increment the count of factors for multiples of i
        }
    }

    // Print the number of factors for each number from 1 to N
    for (int i = 1; i <= N; ++i) {
        cout << "Number: " << i << ", Factors: " << factors[i] << endl;
    }
}

int main() {
    int N;
    cin >> N; // Read the value of N from the user
    countFactors(N); // Call the countFactors function to count the number of factors for each number from 1 to N
    return 0;
}