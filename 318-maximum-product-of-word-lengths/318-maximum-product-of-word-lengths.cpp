class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<bool>> isPresent(n,vector<bool>(26,false));
        for(int i=0;i<n;i++){
            for(auto c:words[i]){
                isPresent[i][c-'a']=true;
            }
        }
        int maxVal=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int isMatching=false;
                for(int k=0;k<26;k++){
                    if(isPresent[i][k] and isPresent[j][k]){
                        isMatching=true;
                        break;
                    }
                }
                if(!isMatching){
                    int val=words[i].size()*words[j].size();
                    maxVal=max(maxVal,val);
                }
            }
        }
        return maxVal;
    }
};