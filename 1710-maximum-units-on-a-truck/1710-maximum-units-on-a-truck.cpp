class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;
        for(auto i:boxTypes){
            vector<int> vt=i;
            v.push_back(make_pair(vt[1],vt[0]));
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(auto i:v){
            if(truckSize>=i.second){
                ans+=i.first*i.second;
                truckSize-=i.second;
            }
            else{
                ans+=i.first*truckSize;
                break;
            }
        }
        return ans;
    }
};