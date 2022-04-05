class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxAmountWater=0;
        while(left<right){
            maxAmountWater=max(maxAmountWater,(right-left)*min(height[left],height[right]));
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxAmountWater;
    }
};