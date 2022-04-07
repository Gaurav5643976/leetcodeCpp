class Solution {
public:
    double solve(double x,int n){
        if(n==0){
            return 1;
        }
        double res=solve(x,n/2);
        if(n&1){
            return res*res*x;
        }
        return res*res;
    }
    double myPow(double x, int n) {
        double pow=solve(x,abs(n));
        if(n<0){
            return 1/pow;
        }
        return pow;
    }
};