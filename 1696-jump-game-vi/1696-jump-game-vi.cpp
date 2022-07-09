class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>> pq;
        pq.push({nums[0],0});
        int maxAns=nums[0];
        for(int i=1;i<n;i++){
            while(i-pq.top()[1]>k){
                pq.pop();
            }
            maxAns=pq.top()[0]+nums[i];
            pq.push({maxAns,i});
        }
        return maxAns;
    }
};