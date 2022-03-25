bool comp(vector<int>&  a, vector<int>& b){
    if(a[0]-a[1]<b[0]-b[1]){
        return true;
    }
    return false;
}
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int n=costs.size()/2;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=costs[i][0]+costs[n+i][1];
        }
        return ans;
    }
};