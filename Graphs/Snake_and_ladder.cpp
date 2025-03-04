// https://www.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minThrow(int N, int arr[]) {
        vector<int> board(31, 0); // Initialize board with 0s

        // Populate snakes and ladders
        for (int i = 0; i < 2 * N; i += 2) {
            board[arr[i]] = arr[i + 1] - arr[i]; // Store the difference
        }

        vector<int> dist(31, INT_MAX); // Initialize distances with infinity
        queue<int> q;

        dist[1] = 0; // Starting cell distance is 0
        q.push(1);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int dice = 1; dice <= 6; ++dice) {
                int next = current + dice;

                if (next <= 30) {
                    int destination = next + board[next]; // Check for snake or ladder, if has, then adds the value of board[next] to next.
                    if (destination > 30) destination = next; // if next is greater than 30, keep next as destination.

                    if (dist[destination] > dist[current] + 1) {
                        dist[destination] = dist[current] + 1;
                        q.push(destination);
                    }
                }
            }
        }

        return dist[30];
    }
};
//=======================================================================================================
class Solution2 {
    public:
        int dijkstra(const vector<int>& board, int start, int end) {
            vector<int> dist(31, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap
    
            dist[start] = 0;
            pq.push({0, start}); // {distance, vertex}
    
            while (!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
    
                if (d > dist[u]) continue; // Skip if distance is outdated
    
                for (int dice = 1; dice <= 6; ++dice) {
                    int next = u + dice;
                    if (next <= 30) {
                        int v = next + board[next];
                        if (v > 30) v = next;
    
                        if (dist[v] > dist[u] + 1) {
                            dist[v] = dist[u] + 1;
                            pq.push({dist[v], v});
                        }
                    }
                }
            }
    
            return dist[end];
        }
    
        int minThrow(int N, int arr[]) {
            vector<int> board(31, 0);
            for (int i = 0; i < 2 * N; i += 2) {
                board[arr[i]] = arr[i + 1] - arr[i];
            }
    
            return dijkstra(board, 1, 30);
        }
    };
    


int main() {
    Solution solution;
    int N = 3; // Number of snakes and ladders
    int arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 
                 17, 4, 19, 7, 27, 1, 21, 9}; // Snakes and ladders positions

    cout << solution.minThrow(N, arr) << endl; // Output: 3

    Solution2 solution2;
    cout << solution2.minThrow(N, arr) << endl; // Output: 3


    return 0;
    
}