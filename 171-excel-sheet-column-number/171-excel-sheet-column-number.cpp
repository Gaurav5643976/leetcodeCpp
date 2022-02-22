class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        long long f=1,n=columnTitle.size();
        for(int i=n-1;i>=0;i--){
            int rem=int(columnTitle[i])%64;
            ans+=f*rem;
            f*=26;
        }
        return ans;
    }
};