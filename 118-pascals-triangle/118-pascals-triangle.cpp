class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                if(j==0 or j==i){
                    row.push_back(1);
                }
                else{
                    row.push_back(ans[ans.size()-1][j-1]+ans[ans.size()-1][j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};