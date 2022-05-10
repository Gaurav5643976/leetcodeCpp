class Solution {
public:
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    void solve(int k,int target,vector<int>& v,int index){
        // if given condition is satisfied push values in ans vector and return
        if(v.size()==k and target==0){
            ans.push_back(v);
            return;
        }
        // if current vector's size is greater than k
        // if index is out of nums's size
        // if target is non takeable 
        // any of these three violation occurs just return
        if(v.size()>k or index>=nums.size() or target<nums[index]){
            return;
        }
        
        // if we are taking current element
        v.push_back(nums[index]);
        solve(k,target-nums[index],v,index+1);
        v.pop_back(); // backtrack
        
        // if we are not taking current element
        solve(k,target,v,index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> v;
        solve(k,n,v,0);
        return ans;
    }
};