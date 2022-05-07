class Solution {
public:
     void solve(vector<vector<int>>& ans,vector<int>& v,vector<int>& c,int remain,int start){
        if(remain<0){
            return;
        }
        if(remain==0){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<c.size();i++){
            if(i>start and c[i]==c[i-1]){
                continue;
            }
            v.push_back(c[i]);
            solve(ans,v,c,remain-c[i],i+1);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(ans,v,candidates,target,0);
        return ans;
    }
};