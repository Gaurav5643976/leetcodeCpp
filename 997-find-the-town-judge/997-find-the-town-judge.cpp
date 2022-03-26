class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans=-1;
        vector<vector<int>> adjList(n,vector<int>());
        vector<bool> vis(n,true);
        for(auto i:trust){
            vis[i[0]-1]=false;
            adjList[i[1]-1].push_back(i[0]-1);
        }
        for(int i=0;i<n;i++){
            if(vis[i] and adjList[i].size()==n-1){
                ans=i+1;
            }
        }
        return ans;
    }
};