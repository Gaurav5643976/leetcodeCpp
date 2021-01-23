// A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

// Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 

// Example 1:


// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// 1 <= mat[i][j] <= 100


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