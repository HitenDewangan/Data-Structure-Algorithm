#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end()); // sort based on starting time because here multiple 
                                        // events can be done under an interval
    int n = events.size();
    int pos = 0;
    int time = 1;
    int attended = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while(pos < n || !minHeap.empty()) { // this while loop represent 1 day
        if(minHeap.empty()) {
            time = max(time, events[pos][0]); // time = when first event start
        }

        // add evnets starting at current pos
        while(pos<n && events[pos][0] == time) {
            minHeap.push(events[pos][1]);
            pos++;
        }

        // remove all already ended (unattended) events
        while(!minHeap.empty() && minHeap.top() < time){
            minHeap.pop();
        }

        //otherwise if the ending date of event is still under time then we can attend
        if(!minHeap.empty()) {
            cout<< "Attending event ending at: " << minHeap.top() << " on day: " << time << endl;
            minHeap.pop();
            attended++;
        }
        time++;   
    }
    return attended;
}


int main() {
    vector<vector<int>> events = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {1, 4}, {3,4}};
    int result = maxEvents(events);
    cout << "Maximum number of events that can be attended: " << result << endl;
    return 0;
}

// T.C. : O(n log n) for sorting and O(n log n) for the priority queue operations
// S.C. : O(n) for the priority queue
// This code finds the maximum number of events that can be attended given their start and end times.
// It uses a greedy approach with a priority queue to efficiently manage the events based on their end