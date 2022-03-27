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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(graph,vis,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};