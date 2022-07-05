class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        nums.clear();
        for(auto i:s){
            nums.push_back(i);
        }
        int n=nums.size(),ans=0,c=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]==1){
                c++;
            }
            else{
                c=1;
            }
            ans=max(ans,c);
        }
        if(n==1){
            return 1;
        }
        return ans;
    }
};