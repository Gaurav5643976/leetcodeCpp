class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<bool>& vis,int node,stack<int>& s){
        vis[node]=true;
        for(auto nbr:g[node]){
            if(!vis[nbr]){
                dfs(g,vis,nbr);
            }
        }
        s.push(node);
    }
    void dfs(vector<vector<int>>& g,vector<bool>& vis,int node){
        vis[node]=true;
        for(auto nbr:g[node]){
            if(!vis[nbr]){
                dfs(g,vis,nbr);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n,vector<int>());
        for(auto i:edges){
            adjList[i[0]].push_back(i[1]);
        }
        vector<bool> vis(n,false);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adjList,vis,i,st);
            }
        }
        vector<bool> vi(n,false);
        while(!st.empty()){
            int f=st.top();
            st.pop();
            if(!vi[f]){
                 dfs(adjList,vi,f);
                ans.push_back(f);
            }
        }
        return ans;
    }
};