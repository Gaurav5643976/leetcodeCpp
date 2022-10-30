class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> obs(m,vector<int>(n,INT_MAX));
        using ti=tuple<int,int,int>;
        queue<ti> q;
        q.push({0,0,0});
        int dis=0;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y,curObs]=q.front();
                q.pop();
                if(x==m-1 and y==n-1){
                    return dis;
                }
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and nx<m and ny>=0 and ny<n){
                        if(curObs+grid[nx][ny]>k or obs[nx][ny]<=curObs+grid[nx][ny]){
                            continue;
                        }
                        q.push({nx,ny,curObs+grid[nx][ny]});
                        obs[nx][ny]=curObs+grid[nx][ny];
                    }
                }
                
            }
            dis++;
        }
        return -1;
    }
};