class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        if(tokens.size()>0 and tokens[0]>power){
            return 0;
        }
        int score=0,ans=0;
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else{
                power+=tokens[j];
                j--;
                score--;
            }
            //cout<<power<<" "<<score<<endl;
            ans=max(ans,score);
        }
        return ans;
    }
};