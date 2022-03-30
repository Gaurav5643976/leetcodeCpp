class Solution {
public:
    void solve(vector<int>& c,int target,int indx,vector<vector<int>>& ans,vector<int>& v){
        int n=c.size();
        if(n==indx){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(target>=c[indx]){
            v.push_back(c[indx]);
            solve(c,target-c[indx],indx,ans,v);
            v.pop_back();
        }
        solve(c,target,indx+1,ans,v);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates,target,0,ans,v);
        return ans;
    }
};