class Solution {
public:
    bool isSafe(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n){
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveCount=0;
                for(int k=0;k<8;k++){
                    int x=dir[k][0]+i,y=dir[k][1]+j;
                    if(isSafe(x,y,m,n) and abs(board[x][y])==1){
                           liveCount++;
                    }
                }
                if(board[i][j]==0 and liveCount==3){
                    board[i][j]=2;
                }
                if(board[i][j]==1 and (liveCount<2 or liveCount>3)){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=board[i][j]>0?1:0;
            }
        }
    }
};