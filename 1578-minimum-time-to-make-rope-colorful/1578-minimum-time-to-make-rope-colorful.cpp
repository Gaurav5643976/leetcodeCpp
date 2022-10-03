class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n=s.size();
        int totalSum=0;
        for(auto i:cost){
            totalSum+=i;
        }
        int leftSum=0;
        for(int i=0;i<n-1;i++){
            int cst=cost[i];
            while(i<n and s[i]==s[i+1]){
                cst=max(cst,cost[i+1]);
                i++;
            }
            //cout<<cst<<" ";
            leftSum+=cst;
        }
        if(n>=2 and s[n-1]!=s[n-2]){
            leftSum+=cost[n-1];
        }
        //cout<<leftSum;
        return totalSum-leftSum;
    }
};