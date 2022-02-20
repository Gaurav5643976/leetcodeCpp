class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int a=intervals[0][0],b=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=b){
                continue;
            }
            else if(a==intervals[i][0] and intervals[i][1]>=b){
                a=intervals[i][0],b=intervals[i][1];
            }
            else{
                ans++;
                a=intervals[i][0],b=intervals[i][1];
            }
        }
        return ans+1;
    }
};