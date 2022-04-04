class Solution {
public:
    int numSquares(int n) {
        // 1=1^2
        // 2=1^2+1^2
        // 3=1^2+1^2+1^2
        // 4=2^2
        // 5=1^1+2^2
        // 6=1^1+1^1+2^2
        // 7=1^1+1^1+1^1+2^2
        vector<int> t(n+1,INT_MAX);
        for(int i=0;i<=n;i++){
            t[i]=i;
            for(int j=1;j*j<=i;j++){
                t[i]=min(t[i],1+t[i-j*j]);
            }
        }
        return t[n];
    }
};