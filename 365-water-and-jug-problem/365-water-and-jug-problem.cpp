class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z==0 or (z<=x+y and z%__gcd(x,y)==0);
    }
};