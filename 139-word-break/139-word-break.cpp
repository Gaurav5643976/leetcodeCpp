class Solution {
public:
    bool solve(string s,unordered_set<string>& d,int start,vector<int>& dp){
        if(start==s.size()){
            return true;
        }
        if(dp[start]!=-1){
            if(dp[start]==1){
                return true;
            }
            else{
                return false;
            }
        }
        string str="";
        for(int i=start;i<s.size();i++){
            str+=s[i];
            if(d.find(str)!=d.end()){
                if(solve(s,d,i+1,dp)){
                    return dp[start]=true;
                }
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(s,dict,0,dp);
    }
};