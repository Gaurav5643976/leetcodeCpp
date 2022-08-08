class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and v[i]<=v[j]){
                    v[i]=v[j]+1;
                    
                }
            }
        }
        return *max_element(v.begin(),v.end());
    }
};