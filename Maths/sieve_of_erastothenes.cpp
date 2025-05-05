// sieve of Eratosthenes
// Time complexity: O(n log log n), where n is the upper limit of the range of numbers to check for primality.
// Space complexity: O(n)

// This algorithm is efficient for finding all prime numbers up to a given limit.
// It works by iteratively marking the multiples of each prime number starting from 2.
// The numbers that remain unmarked at the end are the prime numbers.


// code
#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Initialize all numbers as prime
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}