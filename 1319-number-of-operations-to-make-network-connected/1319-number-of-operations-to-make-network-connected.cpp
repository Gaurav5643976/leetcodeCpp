class Solution {
public:
    void dfs(vector<int> adjList[],int i,vector<bool>& vis){
        vis[i]=true;
        int n=adjList[i].size();
        for(int nbr=0;nbr<n;nbr++){
            if(!vis[adjList[i][nbr]]){
                dfs(adjList,adjList[i][nbr],vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noOfAvailableCables=connections.size();
        if(noOfAvailableCables<n-1){
            return -1;
        }
        vector<int> adjList[n];
        for(auto i:connections){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        int noOfConnectedComponent=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                noOfConnectedComponent++;
                dfs(adjList,i,vis);
            }
        }
        return noOfConnectedComponent-1;
    }
};