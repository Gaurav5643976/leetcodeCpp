class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int a=intervals[0][0],b=intervals[0][1];
        for(int i=1;i<n;i++){
            if(b>=intervals[i][0]){
                b=max(b,intervals[i][1]);
            }
            else{
                ans.push_back({a,b});
                a=intervals[i][0],b=intervals[i][1];
            }
        }
        ans.push_back({a,b});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};