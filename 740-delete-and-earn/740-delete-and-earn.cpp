class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // similer to house robber problem.
        vector<int> freq(10001,0),dp(10001);
        for(auto i:nums){
            freq[i]++;
        }
        dp[0]=0,dp[1]=freq[1];
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
        }
        return dp[10000];
    }
};