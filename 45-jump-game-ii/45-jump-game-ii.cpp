class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,curr=0,ma=0;
        for(int i=0;i<nums.size()-1;i++){
            ma=max(ma,i+nums[i]);
            if(i==curr){
                curr=ma;
                jumps++;
            }
        }
        return jumps;
    }
};