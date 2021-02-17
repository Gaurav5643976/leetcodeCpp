// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10


class Solution {
public:
    vector<int> binary(int i){
        vector<int> ans;
        do{
            ans.push_back(i%2);
            i/=2;
        }while(i);
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int m=pow(2,n);
        set<vector<int>> result;
        for(int i=0;i<m;i++){
            vector<int> bi=binary(i);
            vector<int> res;
            for(int j=0;j<bi.size();j++){
                if(bi[j]){
                    res.push_back(nums[j]);
                }
            }
            sort(res.begin(),res.end());
            result.insert(res);
        }
        vector<vector<int>> ans;
        for(auto i:result){
            ans.push_back(i);
        }
        return ans;
    }
};