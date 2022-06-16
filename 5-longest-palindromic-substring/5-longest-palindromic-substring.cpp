class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,maxLen=1;
        vector<vector<bool>> t(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            t[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                t[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        }
        for(int len =3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                if(s[i]==s[i+len-1] and t[i+1][i+len-2]){
                    t[i][i+len-1]=true;
                    start=i;
                    maxLen=len;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};