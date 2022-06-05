class Solution {
public:
    vector<vector<int>> result;
    bool isSafe(vector<vector<int>> board,int row,int col){
        int i,j,N=board.size();
        for(i=0;i<col;i++){
            if(board[row][i]){
                return false;
            }
        }
        for(i=row,j=col;i>=0 and j>=0;i--,j--){
            if(board[i][j]){
                return false;
            }
        }
        for(i=row,j=col;j>=0 and i<N;i++,j--){
            if(board[i][j]){
                return false;
            }
        }
        return true;
    }
    bool solveUtil(vector<vector<int>>& board,int col){
        int N=board.size();
        if(N==col){
            vector<int> v;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(board[i][j]){
                        v.push_back(j+1);
                    }
                }
            }
            result.push_back(v);
            return true;
        }
        bool res=false;
        for(int i=0;i<N;i++){
            if(isSafe(board,i,col)){
                board[i][col]=1;
                res=solveUtil(board,col+1) || res;
                board[i][col]=0;
            }
        }
        return res;
    }
    vector<vector<int>> nQueens(int n){
        result.clear();
        vector<vector<int>> board(n,vector<int>(n,0));
        if(solveUtil(board,0)==false){
            return {};
        }
        sort(result.begin(),result.end());
        return result;
    }
    int totalNQueens(int n) {
        vector<vector<int>> v=nQueens(n);
        vector<vector<string>> ans;
        string s="",st;
        for(int i=0;i<n;i++){
            s+=".";
        }
        st=s;
        for(auto i:v){
            vector<string> vt;
            for(auto j:i){
                s[j-1]='Q';
                vt.push_back(s);
                s=st;
            }
            ans.push_back(vt);
        }
        int z=ans.size();
        return z;
    }
};