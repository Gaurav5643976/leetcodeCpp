class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,vector<int>> mv;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mv[i-j].push_back(mat[i][j]);
            }
        }
        for(int i=n-1;i>=-m+1;i--){
            sort(mv[i].begin(),mv[i].end());
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=mv[i-j].front();
                auto itr=mv[i-j].begin();
                mv[i-j].erase(itr);
            }
        }
        return ans;
    }
};