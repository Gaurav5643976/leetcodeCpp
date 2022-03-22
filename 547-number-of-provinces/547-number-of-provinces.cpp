class Solution {
public:
    void dfs(vector<vector<int>> g,vector<bool>& v,int i){
        v[i]=true;
        for(int j=0;j<g[i].size();j++){
            if(g[i][j]==1 and !v[j]){
                dfs(g,v,j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfProvinces=0;
        int noOfCities=isConnected.size();
        vector<bool> vis(noOfCities,false);
        for(int i=0;i<noOfCities;i++){
            if(!vis[i]){
                noOfProvinces++;
                dfs(isConnected,vis,i);
            }
        }
        return noOfProvinces;
    }
};