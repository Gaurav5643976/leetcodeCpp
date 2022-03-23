class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<vector<int>>> adjList(2,vector(n,vector<int>()));
        for(auto i:redEdges){
            adjList[0][i[0]].push_back(i[1]);
        }
        for(auto i:blueEdges){
            adjList[1][i[0]].push_back(i[1]);
        }
        vector<vector<int>> temp(2,vector<int>(n,2*n));
        temp[0][0]=temp[1][0]=0;
        queue<vector<int>> q;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(auto i:adjList[1-v[1]][v[0]]){
                if(temp[1-v[1]][i]==2*n){
                    temp[1-v[1]][i]=1+temp[v[1]][v[0]];
                    q.push({i,1-v[1]});
                }
            }
        }
        for(int i=0;i<n;i++){
            int mn=min(temp[0][i],temp[1][i]);
            if(mn!=2*n){
                ans[i]=mn;
            }
        }
        return ans;
    }
};