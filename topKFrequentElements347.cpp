// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
// You can return the answer in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }
        // for(auto  i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end());
        int n=v.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[n-1-i].second);
        }
        return ans;
    }
};