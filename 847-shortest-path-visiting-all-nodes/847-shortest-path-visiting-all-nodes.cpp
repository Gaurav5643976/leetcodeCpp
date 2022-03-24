class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1){
            return 0;
        }
        int finalState=(1<<n)-1;
        vector<vector<bool>> vis(n,vector<bool>(finalState+1,false));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            vis[i][1<<i]=true;
        }
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            if(v[1]==finalState){
                return v[2];
            }
            for(auto i:graph[v[0]]){
                int newVisitedState=v[1]|(1<<i);
                if(!vis[i][newVisitedState]){
                    vis[i][newVisitedState]=true;
                    q.push({i,newVisitedState,v[2]+1});
                }
            }
        }
        return 0;
    }
};