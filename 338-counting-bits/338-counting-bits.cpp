class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int count=0,j=i;
            while(j){
                count+=j%2;
                j/=2;
            }
            ans[i]=count;
        }
        return ans;
    }
};