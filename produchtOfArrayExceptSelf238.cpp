// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> start(n),end(n);
        start[0]=end[0]=1;
        for(int i=1;i<n;i++){
            start[i]=start[i-1]*nums[i-1];
            end[i]=end[i-1]*nums[n-i];
        }
        for(int i=0;i<n;i++){
            start[i]=start[i]*end[n-1-i];
        }
        return start;
    }
};