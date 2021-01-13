// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(s.find(x)!=s.end()){
                v.push_back(i);
                v.push_back(s[x]);
            }
            else{
                s[nums[i]]=i;
            }
        }
        return v;
    }
};