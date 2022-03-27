class Solution {
public:
    bool dfs(vector<vector<int>>& g,vector<int>& vis,int node,int color){
        vis[node]=color;
        for(auto nbr:g[node]){
            if(vis[nbr]==-1){
                if(!dfs(g,vis,nbr,1-color)){
                    return false;
                }
            }
            else if(vis[node]==vis[nbr]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n,vector<int>());
        for(auto i:dislikes){
            adjList[i[0]-1].push_back(i[1]-1);
            adjList[i[1]-1].push_back(i[0]-1);
        }
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(adjList,vis,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};