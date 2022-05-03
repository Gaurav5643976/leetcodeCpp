// bool comp(const vector<int>& v1,const vector<int>& v2){
//     if(v1[0]!=v2[0]){
//         return v1[0]<v2[0];
//     }
//     if(v1[1]<0 and v2[1]<0){
//         return v1[1]>v2[1];
//     }
//     if(v1[1]<0){
//         return true;
//     }
//     if(v2[1]<0){
//         return false;
//     }
//     return v1[1]<v2[1];
// }
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        for(auto building:buildings){
            v.push_back({building[0],-building[2]});
            v.push_back({building[1],building[2]});
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        map<int,int,greater<int>> pq;
        pq[0]=1;
        int preMax=0;
        for(auto i:v){
            if(i[1]<0){
                pq[-i[1]]++;
            }
            else{
                pq[i[1]]--;
                if(pq[i[1]]==0){
                    pq.erase(i[1]);
                }
            }
            int currMax=pq.begin()->first;
            if(preMax!=currMax){
                ans.push_back({i[0],currMax});
                preMax=currMax;
            }
        }
        return ans;
    }
};