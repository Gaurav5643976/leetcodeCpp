class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        vector<int> v(m,0);
        prefixSum.push_back(v);
        for(auto i:matrix){
            for(int j=0;j<m;j++){
                v[j]+=i[j];
            }
            prefixSum.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        int noOfRow=row2-row1+1;
        for(int i=col1;i<=col2;i++){
            ans+=prefixSum[row1+noOfRow][i]-prefixSum[row1][i];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */