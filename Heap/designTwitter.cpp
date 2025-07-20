#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [{time, tweetId}]
    unordered_map<int, unordered_set<int>> followees; // userId -> set of followeeId
    
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        
        // Add user's own tweets
        for (const auto& tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }
        
        // Add tweets from followees
        for (int followeeId : followees[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < 10 && !maxHeap.empty(); ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

// =========== Example Usage ===========
int main() {
    Twitter twitter;
    
    twitter.postTweet(1, 5); // User 1 posts a tweet with tweetId 5.
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a tweet with tweetId 6.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with a tweet id -> [5], since user 1 is no longer following user 2.
    
    return 0;
}