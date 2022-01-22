class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n+1,false);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(!t[i-j*j]){
                    t[i]=true;
                    break;
                }
                
            }
        }
        return t[n];
    }
};