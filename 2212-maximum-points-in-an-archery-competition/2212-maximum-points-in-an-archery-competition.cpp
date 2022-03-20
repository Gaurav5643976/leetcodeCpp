class Solution {
public:
    vector<int> v={0,0,0,0,0,0,0,0,0,0,0,0};
    int m=0;
    void solve(int& ma,int i,vector<int>& ans,vector<int>& aA){
        if(ma<=0 or i<=0){
            ans[0]=ma;
            int sum=0;
            i--;
            for(int j=0;j<12;j++){
                if(aA[j]<ans[j]){
                    sum+=j;
                }
            }
            if(sum>m){
                m=sum;
                v=ans;
            }
            return;
        }
        if(ma>aA[i]){
            vector<int> u=ans;
            u[i]=aA[i]+1;
            int k=ma-aA[i]-1;
            solve(k,i-1,u,aA);
        }
        solve(ma,i-1,ans,aA);
        
    }
    vector<int> maximumBobPoints(int nA, vector<int>& aA) {
        vector<int> ans(12,0);
        solve(nA,11,ans,aA);
        return v;
    }
};