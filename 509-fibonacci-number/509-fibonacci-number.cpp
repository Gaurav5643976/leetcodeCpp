class Solution {
public:
    int fib(int n) {
        if(n<2){
            return n;
        }
        int x=0,y=1,z;
        n--;
        while(n--){
            z=x+y;
            x=y;
            y=z;
        }
        return z;
    }
};