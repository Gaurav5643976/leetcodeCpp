class Solution {
public:
    unordered_set<int> st;
    int solve(int today,int lastDay, vector<int>& costs,vector<int>& dp){
        if(today>lastDay){
            return 0;
        }
        if(dp[today]!=-1){
            return dp[today];
        }
        int ans=INT_MAX;
        if(st.find(today)!=st.end()){
            ans=costs[0]+solve(today+1,lastDay,costs,dp);
            ans=min(ans,costs[1]+solve(today+7,lastDay,costs,dp));
            ans=min(ans,costs[2]+solve(today+30,lastDay,costs,dp));
        }
        else{
            ans=solve(today+1,lastDay,costs,dp);
        }
        return dp[today]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,-1);
        sort(days.begin(),days.end());
        for(auto i:days){
            st.insert(i);
        }
        return solve(days[0],days[days.size()-1],costs,dp);
    }
};