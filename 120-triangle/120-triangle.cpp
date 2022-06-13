class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int t[n];
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(i==n-1){
                    t[j]=triangle[i][j];
                }
                else{
                    int mi=min(t[j],t[j+1]);
                    t[j]=triangle[i][j]+mi;
                }
            }
        }
        return t[0];
    }
};