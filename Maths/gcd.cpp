// GCD : greatest common divisor

// Code
#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate GCD of an array of numbers
int gcdArray(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "GCD of the array is: " << gcdArray(arr, n) << endl;
    return 0;
}