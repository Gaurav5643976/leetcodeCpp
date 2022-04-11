class Twitter {
public:
    unordered_map<int,set<int>> follows;
    vector<pair<int,int>> tweetsList;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsList.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int n=tweetsList.size();
        for(int i=n-1;i>=0;i--){
            if(userId==tweetsList[i].first){
                feed.push_back(tweetsList[i].second);
            }
            else if(follows[userId].find(tweetsList[i].first)!=follows[userId].end()){
                feed.push_back(tweetsList[i].second);
            }
            if(feed.size()>=10){
                break;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */