class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size(),n=matrix[0].size();
        int noOfMoves=m*n;
        int i=0,j=0;
        char dir='R';
        while(noOfMoves--){
            ans.push_back(matrix[i][j]);
            matrix[i][j]=INT_MAX;
            if(dir=='R'){
                if(j+1<n and matrix[i][j+1]!=INT_MAX){
                    j++;
                }
                else{
                    i++;
                    dir='D';
                }
            }
            else if(dir=='D'){
                if(i+1<m and matrix[i+1][j]!=INT_MAX){
                    i++;
                }
                else{
                    j--;
                    dir='L';
                }
            }
            else if(dir=='L'){
                if(j-1>=0 and matrix[i][j-1]!=INT_MAX){
                    j--;
                }
                else{
                    i--;
                    dir='U';
                }
            }
            else if(dir=='U'){
                if(i-1>=0 and matrix[i-1][j]!=INT_MAX){
                    i--;
                }
                else{
                    j++;
                    dir='R';
                }
            }
        }
        return ans;
    }
};