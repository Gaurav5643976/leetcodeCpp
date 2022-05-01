class Solution {
public:
    int numTrees(int n) {
        int t[n+1];
        t[0]=1;
        for(int i=1;i<=n;i++){
            int ans=0;
            for(int j=1;j<=i;j++){
                int left=j-1,right=i-j;
                //cout<<left<<" "<<right<<endl;
                ans=ans+t[left]*t[right];
            }
            t[i]=ans;
        }
        return t[n];
    }
};