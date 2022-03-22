class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0;i<n;i++){
            ans+='a';
            k--;
        }
        for(int i=0;i<n;i++){
            int mn=min(k,25);
            k-=mn;
            ans[i]+=mn;
            if(k==0){
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};