class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        set<pair<int,int>> s;
        vector<vector<int>> adjList(n,vector<int>());
        for(auto i:connections){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
            s.insert({i[0],i[1]});
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(!vis[node]){
                vis[node]=true;
                for(auto i:adjList[node]){
                    q.push(i);
                    if(!vis[i] and s.count({node,i})){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};