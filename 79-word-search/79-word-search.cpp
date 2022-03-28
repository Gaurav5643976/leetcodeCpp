class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int indx,int m,int n,int i,int j){
        if(indx==word.size()){
            return true;
        }
        if(i<0 or i>=m or j<0 or j>=n or word[indx]!=board[i][j]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='*';
        if(dfs(board,word,indx+1,m,n,i-1,j) or dfs(board,word,indx+1,m,n,i,j-1) or dfs(board,word,indx+1,m,n,i+1,j) or dfs(board,word,indx+1,m,n,i,j+1)){
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(board,word,0,m,n,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};