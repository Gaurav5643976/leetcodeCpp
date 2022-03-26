class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};