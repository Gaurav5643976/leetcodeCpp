class Solution {
public:
    int countVowelStrings(int n) {
        int i=1;
        int A[]={1,1,1,1,1};
        while(i!=n){
            for(int i=3;i>=0;i--){
                A[i]+=A[i+1];
            }
            i++;
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=A[i];
        }
        return ans;
    }
};