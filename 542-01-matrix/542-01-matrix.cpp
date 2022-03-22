class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        //vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    matrix[i][j]=-1;
                }
                else{
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int a=q.front().first,b=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int x=a+v[j][0],y=b+v[j][1];
                if(x>=0 and x<m and y>=0 and y<n and matrix[x][y]==-1){
                    matrix[x][y]=matrix[a][b]+1;
                    q.push({x,y});
                }
            }
        }
        return matrix;
    }
};