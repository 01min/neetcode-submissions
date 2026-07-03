class Twitter {
private:
    int time; 
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> follows;   

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int, int>> feedSet;
        int mySize = tweets[userId].size();
        for (int i = max(0, mySize - 10); i < mySize; ++i) {
            feedSet.insert({-tweets[userId][i].first, tweets[userId][i].second});
        }
        for (int followeeId : follows[userId]) {
            int fSize = tweets[followeeId].size();
            for (int i = max(0, fSize - 10); i < fSize; ++i) {
                feedSet.insert({-tweets[followeeId][i].first, tweets[followeeId][i].second});
            }
        }
        vector<int> result;
        auto it = feedSet.begin();
        while (it != feedSet.end() && result.size() < 10) {
            result.push_back(it->second);
            it++;
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};