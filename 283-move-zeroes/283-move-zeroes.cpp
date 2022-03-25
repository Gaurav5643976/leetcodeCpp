class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(count==n-i){
                break;
            }
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                i--;
                count++;
            }
        }
    }
};