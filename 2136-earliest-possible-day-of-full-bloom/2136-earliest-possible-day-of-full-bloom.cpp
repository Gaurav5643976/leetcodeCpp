class Solution {
public:
    static bool comp(const pair<int,int>&a,const pair<int,int>&b){
        return a.second>b.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>>arr;
        
        for(int i=0;i<plantTime.size();i++)
            arr.push_back({i,growTime[i]});
        
        sort(arr.begin(),arr.end(),comp);
        
        int res=0,cur=0;
        
        for(auto i:arr){
            cur+=plantTime[i.first];
            res=max(res,cur+growTime[i.first]);
        }
        
        return res;
    }
};