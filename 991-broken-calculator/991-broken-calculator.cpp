class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count=0;
        while(Y>X){
            Y=Y&1?Y+1:Y/2;
            count++;
        }
        return count+X-Y;
    }
};