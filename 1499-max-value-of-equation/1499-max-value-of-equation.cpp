class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans=INT_MIN;
        priority_queue<pair<int,int>> pq;
        for(auto i:points){
            while(!pq.empty() and i[0]-pq.top().second>k){
                pq.pop();
            }
            if(!pq.empty()){
                ans=max(ans,i[0]+i[1]+pq.top().first);
            }
            pq.push({i[1]-i[0],i[0]});
        }
        return ans;
    }
};