class Solution {
public:
    int value(char v){
        if(v=='I'){
            return 1;
        }
        else if(v=='V'){
            return 5;
        }
        else if(v=='X'){
            return 10;
        }
        else if(v=='L'){
            return 50;
        }
        else if(v=='C'){
            return 100;
        }
        else if(v=='D'){
            return 500;
        }
        else if(v=='M'){
            return 1000;
        }
        return -1;
    }
    int romanToInt(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int a=value(s[i]);
            if(i+1<n){
                int b=value(s[i+1]);
                if(b<=a){
                    ans+=a;
                }
                else{
                    ans+=b-a;
                    i++;
                }
            }
            else{
                ans+=a;
            }
        }
        return ans;
    }
};