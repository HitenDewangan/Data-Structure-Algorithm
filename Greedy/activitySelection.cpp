/* [Naive Approach] Generate All Subsets - O(n^2 * 2^n) Time and O(n) Space
How does Greedy Choice work for Activities sorted according to finish time? 
[Expected Approach 1] - Using Sorting - O(n * log(n)) Time and O(n) Space
[Expected Approach 2] - Using Priority Queue - O(n * log(n)) Time and O(n) Space 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxActivities(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    if (n == 0) return 0;

    // Pairing start and finish times
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) {
        activities[i] = {finish[i], start[i]};
    }

    // Sort activities based on finish times
    sort(activities.begin(), activities.end());

    // Select the first activity
    int count = 1;
    int lastFinishTime = activities[0].first;

    // Iterate through the sorted activities
    for (int i = 1; i < n; ++i) {
        if (activities[i].second >= lastFinishTime) {
            count++;
            lastFinishTime = activities[i].first;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 5, 6};
    vector<int> finish = {2, 4, 6, 7, 8, 9};

    int maxAct = maxActivities(start, finish);
    cout << "Maximum number of activities that can be performed: " << maxAct << endl;

    return 0;
}   