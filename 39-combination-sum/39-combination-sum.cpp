class Solution {
public:
    void solve(vector<int>& c,int target,vector<int>& v,vector<vector<int>>& ans,int i){
        if(i==c.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        // if take present element
        if(c[i]<=target){
            v.push_back(c[i]);
            solve(c,target-c[i],v,ans,i);
            v.pop_back();
        }
        //if not take the present element
        solve(c,target,v,ans,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates,target,v,ans,0);
        return ans;
    }
};