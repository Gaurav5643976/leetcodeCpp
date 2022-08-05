class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<unsigned int> t(target+1,0);
        t[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(nums[j]<=i){
                    t[i]+=t[i-nums[j]];
                }
                else{
                    break;
                }
            }
        }
        return t[target];
    }
    
};