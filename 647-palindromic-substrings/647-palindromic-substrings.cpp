class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=n;
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++){
            mat[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                ans++;
                mat[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(mat[i+1][j-1] && s[i]==s[j]){
                    mat[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};