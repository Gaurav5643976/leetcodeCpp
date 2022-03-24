class Solution {
public:
    int reverse(int x) {
        int num=abs(x);
        long long reverseX=0;
        while(num){
            reverseX=reverseX*10+num%10;
            num/=10;
        }
        if(x<0){
            reverseX*=-1;
        }
        if(reverseX<INT_MIN or reverseX>INT_MAX){
            return -0;
        }
        return (int)reverseX;
    }
};