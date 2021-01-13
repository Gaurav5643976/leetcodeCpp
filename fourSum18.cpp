// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [], target = 0
// Output: []
 

// Constraints:

// 0 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109





class Solution {
public:
    vector< vector <int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                m[nums[i]+nums[j]].push_back(i);
                m[nums[i]+nums[j]].push_back(j);
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int k=target-nums[i]-nums[j];
                if(m.find(k)!=m.end()){
                    vector<int> w=m[k];
                    for(int z=0;z<w.size();z=z+2){
                        if(i!=w[z] && i!=w[z+1] && j!=w[z] && j!=w[z+1]){
                            vector<int> v{nums[i],nums[j],nums[w[z]],nums[w[z+1]]};
                            sort(v.begin(),v.end());
                            ans.insert(v);
                        }
                    }
                }
            }
        }
        vector<vector<int>> u;
        for(auto i:ans){
            u.push_back(i);
        }
        return u;
    }
};