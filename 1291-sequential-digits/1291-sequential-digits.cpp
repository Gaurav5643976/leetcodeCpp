class Solution {
public:
    int noOfDigits(int n){
        int c=0;
        while(n){
            n/=10;
            c++;
        }
        return c;
    }
    vector<int> solve(int i,int low,int high){
        vector<int> v;
        long long temp=0,toAdd=0;
        for(int j=1;j<=i;j++){
            temp=temp*10+j;
            toAdd=10*toAdd+1;
        }
        while(noOfDigits(temp)==i){
            if(temp>=low and temp<=high){
                v.push_back(temp);
            }
            if(temp%10==9){
                break;
            }
            
            temp+=toAdd;
        }
        return v;
    }
    vector<int> sequentialDigits(int low, int high) {
        int minDig=0,maxDig=0;
        int l=low,h=high;
        while(l){
            minDig++;
            l/=10;
        }
        while(h){
            maxDig++;
            h/=10;
        }
        vector<int> ans;
        for(int len=minDig;len<=maxDig;len++){
            vector<int> v=solve(len,low,high);
            for(auto i:v){
                ans.push_back(i);
            }
        }
        return ans;
    }
};