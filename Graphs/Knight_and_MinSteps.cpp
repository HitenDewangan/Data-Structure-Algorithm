#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Possible moves of a knight
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y, int boardSize) {
    return x >= 0 && x < boardSize && y >= 0 && y < boardSize;
}

int minKnightSteps(int startX, int startY, int targetX, int targetY, int boardSize) {

    if (!isValid(startX, startY, boardSize) || !isValid(targetX, targetY, boardSize)) {
        return -1;
    }

    if (startX == targetX && startY == targetY) {
        return 0;
    }

    vector<vector<int>> dist(boardSize, vector<int>(boardSize, INT_MAX));

    queue<pair<int, int>> q;

    // Set the starting position distance to 0 and enqueue it
    dist[startX][startY] = 0;
    q.push({startX, startY});

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        // Explore all possible knight moves
        for (int i = 0; i < 8; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // Check if the next position is within the board and hasn't been visited yet
            if (nextX >= 0 && nextX < boardSize && nextY >= 0 && nextY < boardSize && dist[nextX][nextY] == INT_MAX) {
                // Update the distance and enqueue the next position
                dist[nextX][nextY] = dist[x][y] + 1;
                q.push({nextX, nextY});

                // If the target position is reached, return the distance
                if (nextX == targetX && nextY == targetY) {
                    return dist[nextX][nextY];
                }
            }
        }
    }

    // If the target position is not reachable, return -1
    return -1;
}

int main() {
    int boardSize = 8; // Example: 8x8 chessboard
    int startX, startY, targetX, targetY;

    cout << "Enter the starting position (x y): ";
    cin >> startX >> startY;

    cout << "Enter the target position (x y): ";
    cin >> targetX >> targetY;

    int steps = minKnightSteps(startX, startY, targetX, targetY, boardSize);

    if (steps != -1) {
        cout << "Minimum number of steps: " << steps << endl;
    } else {
        cout << "Target position is not reachable." << endl;
    }

    return 0;
}