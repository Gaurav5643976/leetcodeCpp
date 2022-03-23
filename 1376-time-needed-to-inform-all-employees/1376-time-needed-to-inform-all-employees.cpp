class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        vector<vector<int>> adjList(n,vector<int>());
        for(int i=0;i<n;i++){
            if(i!=headID){
                adjList[manager[i]].push_back(i);
            }
        }
        queue<vector<int>> q;
        q.push({headID,0});
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            ans=max(ans,v[1]);
            for(auto i:adjList[v[0]]){
                q.push({i,v[1]+informTime[v[0]]});
            }
        }
        return ans;
    }
};