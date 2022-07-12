class Solution {
public:
     bool equalHalves(int n,int a,int b,int c,int d,vector<int>& matchsticks){
           
        if(n==0){
            return (a==0 && b==0 && c==0);
        }
        
        if(matchsticks[n-1]<=a && equalHalves(n-1,a-matchsticks[n-1],b,c,d,matchsticks))
            return true;
        else if(matchsticks[n-1]<=b && equalHalves(n-1,a,b-matchsticks[n-1],c,d,matchsticks))
            return true;
        else if(matchsticks[n-1]<=c && equalHalves(n-1,a,b,c-matchsticks[n-1],d,matchsticks))
            return true;
        else if(matchsticks[n-1]<=d && equalHalves(n-1,a,b,c,d-matchsticks[n-1],matchsticks))
            return true;
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        sort(matchsticks.begin(),matchsticks.end());      
        int n=matchsticks.size();
        
        int sum=0;
        sum=accumulate(matchsticks.begin(),matchsticks.end(),sum);
        
        if(sum%4!=0)
            return false;
        
        int a=sum/4;
        
        return equalHalves(n,a,a,a,a,matchsticks);
    }
};