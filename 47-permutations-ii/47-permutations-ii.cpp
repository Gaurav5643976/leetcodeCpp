class Solution {
public:
    void solve(vector<int>& nums,vector<int> v,set<vector<int>>& ans){
        if(nums.size()==0){
            ans.insert(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> u=v,w=nums;
            u.push_back(nums[i]);
            w.erase(w.begin()+i);
            solve(w,u,ans);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> v;
        solve(nums,v,res);
        vector<vector<int>> ans;
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};