class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),start=0,maxLen=0;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            if(um.find(s[i])!=um.end()){
                start=max(um[s[i]]+1,start);
            }
            um[s[i]]=i;
            maxLen=max(maxLen,i-start+1);
        }
        return maxLen;
    }
};