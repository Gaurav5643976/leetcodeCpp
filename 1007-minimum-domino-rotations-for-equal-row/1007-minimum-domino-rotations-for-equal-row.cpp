class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int T[6]={0},B[6]={0};
        for(auto i:tops){
            T[i-1]++;
        }
        for(auto i:bottoms){
            B[i-1]++;
        }
        vector<int> v;
        int n=tops.size();
        for(int i=0;i<6;i++){
            if(T[i]+B[i]>=n){
                for(int j=0;j<n;j++){
                    if(tops[j]!=i+1 and bottoms[j]!=i+1){
                        break;
                    }
                    if(j==n-1){
                        v.push_back(i);
                    }
                }
            }
        }
        if(v.size()==0){
            return -1;
        }
        int ans=INT_MAX;
        for(auto i:v){
            ans=min(ans,min(n-T[i],n-B[i]));
        }
        return ans;
    }
};