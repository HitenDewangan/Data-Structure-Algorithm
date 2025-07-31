/*
Given N student marks, Each student is allocated chocolates, 
find min no. of chocolates required to allocate to all students;
Note1 : every person compares marks to their adjacent persons, 
        if a student get more marks than their adjacent then they also get more chocolates. 
Note2 : Every student should also get at least 1 chocolate.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int minChocolates(vector<int>& marks) {
    int n = marks.size();
    if (n == 0) return 0;
    
    vector<int> chocolates(n, 1);
    
    // Left to right pass
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[i-1]) {
            chocolates[i] = chocolates[i-1] + 1;
        }
    }
    
    // Right to left pass
    for (int i = n-2; i >= 0; --i) {
        if (marks[i] > marks[i+1]) {
            chocolates[i] = max(chocolates[i], chocolates[i+1] + 1);
        }
    }

    // print the chocolates distribution for debugging
    cout << "Chocolates distribution: ";
    for (int choco : chocolates) {
        cout << choco << " ";
    }
    cout << endl;
    
    return accumulate(chocolates.begin(), chocolates.end(), 0);
}

int main() {
    vector<int> marks = {1, 6, 3, 1, 10, 12, 20, 5, 2, 1};
    int result = minChocolates(marks);
    cout << "Minimum chocolates required: " << result << endl;
    return 0;
}