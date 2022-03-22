class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>& q,vector<vector<int>>& vis,int m,int n){
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for(auto i:dir){
                int x=p.first+i[0],y=p.second+i[1];
                if(x>=0 and x<m and y>=0 and y<n and !vis[x][y] and heights[x][y]>=heights[p.first][p.second]){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> visPacific(m,vector<int>(n,0));
        vector<vector<int>> visAtlantic(m,vector<int>(n,0));
        queue<pair<int,int>> qp,qa;
        for(int i=0;i<m;i++){
            qp.push({i,0});
            visPacific[i][0]=1;
            qa.push({i,n-1});
            visAtlantic[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            qp.push({0,i});
            visPacific[0][i]=1;
            qa.push({m-1,i});
            visAtlantic[m-1][i]=1;
        }
        bfs(heights,qp,visPacific,m,n);
        bfs(heights,qa,visAtlantic,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visPacific[i][j] and visAtlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};